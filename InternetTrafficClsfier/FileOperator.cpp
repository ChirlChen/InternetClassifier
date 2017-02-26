#include "FileOperator.h"
#include "StrOperator.h"
#include "ClassifyAlgorithm.h"
#include "MyString.h"
#include "debug_new.h"
#include <assert.h>

const CMyString INTERNET_TRAFFIC_TYPE[9] = {"WWW", "FTP", "MAIL", "P2P", 
                                            "ATTACK", "DATABASE", "SERVIES", 
                                            "INTERACTIVE", "MULTIMEDIA"};

std::vector<unsigned short> CFileOperator::m_AttriPos;
short CFileOperator::m_AttriNum = 0;
CFileOperator::CFileOperator(QObject *aParent)
  : m_PrePointer(NULL),
    m_StrBuf(new char[BUF_SIZE]),
    m_FilePath(NULL)
{
  qRegisterMetaType<SDataPack>("SDataPack");
  qRegisterMetaType<EOperateFlag>("EOperateFlag");
  memset(m_StrBuf, 0, BUF_SIZE);
  
}

CFileOperator::~CFileOperator(void)
{
  IF_NOT_NULL_DELETE_a(m_StrBuf);
  IF_NOT_NULL_DELETE_a(m_FilePath);
  IF_NOT_NULL_DELETE_a(m_PrePointer);
  CStatisticBayes::destroyInstance();
}

CMyString &CFileOperator::sliceStr(const char *aSrc, CMyString &aDest, const char aChar, bool aIsNeedTheData)
{
  if (aSrc == NULL)
  { return aDest;}

  m_PrePointer = const_cast<char *>(aSrc);
  int idx = 0;
  bool isFloat = false;
  if (aIsNeedTheData)
  {
    while ((*m_PrePointer) != aChar && (*m_PrePointer) != '\0')
    {
      if ((*m_PrePointer) == ' ') //去除空格;
      {
        m_PrePointer++;
        continue;
      }
      if ((*m_PrePointer) == '.') //处理小数，实现连续型变量离散化;
      {
        for (int loop = 0; loop < idx; ++loop)  
        {
          if (aDest.getBuf()[loop] != '0')//小数点前有非零整数，直接返回;
          {
            return aDest;
          }
        }
        isFloat = true;
      }

      aDest.append(*m_PrePointer); //存当前字符;
      if (isFloat && *m_PrePointer > '0' && *m_PrePointer <= '9')
      {
        return aDest; //小数点后出现第一个非零数,就返回;
      }
      m_PrePointer++;
      idx++;
    }
  }
  else
  {
    while ((*m_PrePointer) != aChar && (*m_PrePointer) != '\0')
    {
      m_PrePointer++;
    }
  }

  if (*m_PrePointer == aChar)
  {
    m_PrePointer++;
  }

  return aDest;
}

bool CFileOperator::setAttriPosArray(std::ifstream &aMyFile, ushort *aSrcArray, const int &aSize)
{
  if (aSrcArray == NULL || aSize <= 0)
  {
    return false;
  }
  
  m_AttriNum = aSize;
  while ((*aSrcArray) == 0)
  {
    aSrcArray++;
  }

  ushort currentPos = 0;
  int savedNum = 0;
  m_AttriPos.clear();
  while (!aMyFile.eof())
  {
    memset(m_StrBuf, 0, BUF_SIZE);
    aMyFile.getline(m_StrBuf, BUF_SIZE);

    //存所有属性值;
    bool isPickOutAttri = false;
    if (m_StrBuf[0] == '@')
    {
      EPickOutAttriResult reslt = pickOutAttriNum(m_StrBuf, (*aSrcArray));
      if (EPOAR_IsTarget == reslt)
      {
        m_AttriPos.push_back(currentPos);
        ++aSrcArray;
        ++savedNum;
        ++currentPos;
        if (savedNum == aSize)  //需要保存的属性值位置保存完毕;
        { return true;}
      }
      else if (EPOAR_IsNum == reslt)
      {
        ++currentPos;
      }
    }
  }
  return false;
}

EPickOutAttriResult CFileOperator::pickOutAttriNum(const char *aStr, ushort &aTargetNum)
{
  if (aStr == NULL)
  { return EPOAR_NotNum;}

  //存所有属性值,去掉@attribute,存下后面的值;
  if (aStr[0] == '@')
  {
    int idx = 1;
    while ((aStr[idx] < '0' || aStr[idx] > '9') && aStr[idx] != '\0')
    {
      idx++;
    }
    if (aStr[idx] >= '0' && aStr[idx] <= '9')
    {
      int tempNum = CStrOperator::getInstance()->str2ushort(&aStr[idx]);
      if (tempNum > 0 && tempNum == aTargetNum)
      {
        return EPOAR_IsTarget;
      }
      else if (tempNum > 0)
      {
        return EPOAR_IsNum;
      }
    }
  }
  return EPOAR_NotNum;
}

const std::vector<unsigned short> &CFileOperator::getAttriPos()
{
  return m_AttriPos;
}

void CFileOperator::statisticData()
{

}

bool CFileOperator::operateTrainingFile(ushort *aSrcArray, const int &aSize, const char *aFilePath)
{
  const char *myFilePath = aFilePath ? aFilePath : m_FilePath; 
  if (myFilePath == NULL)
  { return false;}

  CStatisticBayes::getInstance()->clearTrainingData(); //每次进行统计数据前，先清空容器里面的旧数据;

  std::ifstream myFile;
  myFile.open(myFilePath);
  if (!myFile.is_open())
  { return false;}
  
  if (!setAttriPosArray(myFile,aSrcArray, aSize))  //设置属性值的位置;
  { return false;}

  CStatisticBayes::getInstance()->mallocMemory4AllTypeAttri(aSize);    //为数据容器申请内存;
  std::vector<ushort>::iterator itor = m_AttriPos.begin();
  while (!myFile.eof())
  {
    memset(m_StrBuf, 0, BUF_SIZE);
    myFile.getline(m_StrBuf, BUF_SIZE);

    m_PrePointer = m_StrBuf;
    
    //从数值开始存储统计数据;
    if (m_PrePointer[0] >= '0' && m_PrePointer[0] <= '9')
    {
      char *tempPtr = m_StrBuf; 
      CMyString tempTrafficType;
      while (!getTrafficType(tempPtr, tempTrafficType)) //如果有数据格式错误，便进行拼接;
      {
        char temBuf[BUF_SIZE] = {'\0'};
        myFile.getline(temBuf, BUF_SIZE);
        strcat_s(m_StrBuf, BUF_SIZE, temBuf);
        
        tempPtr = temBuf;
      }

      //开始统计数据;
      itor = m_AttriPos.begin();
      CMyString tempStr; //用于临时存储各属性值里的变量;
      ushort idx = 0; //对应属性值存储的位置;
      ushort curAttriPos = 0; //当前属性值的位置;
      CStatisticBayes::getInstance()->statisticTrafficType(str2Enum(tempTrafficType));
      do  
      {
        tempStr.clearData();
        if (curAttriPos == *itor) //所需要的属性;
        {
          sliceStr(m_PrePointer, tempStr, ',', true);
          ++itor;
          CStatisticBayes::getInstance()->statisticAllTypeAttri(str2Enum(tempTrafficType), idx, tempStr);
          ++idx;
        }
        else
          sliceStr(m_PrePointer, tempStr, ',', false);
        ++curAttriPos;
      } while (itor != m_AttriPos.end());  //直到统计完所有属性值;
    }
  }//数据统计结束;

  CStatisticBayes::getInstance()->calcStatisticRate();  //计算统计数据的概率;

  m_PrePointer = NULL;
  myFile.close();
  return true;
}

bool CFileOperator::operateClassifyFile(const char *aFilePath /* = NULL */)
{
  if (m_AttriPos.empty())
  { return false;}
  
  const char *myFilePath = aFilePath ? aFilePath : m_FilePath; 
  if (myFilePath == NULL)
  { return false;}

  CStatisticBayes::getInstance()->clearClassifyData(); //每次进行统计数据前，先清空容器里面的旧数据;

  std::ifstream myFile;
  myFile.open(myFilePath);
  if (!myFile.is_open())
  { return false;}

  std::vector<ushort>::iterator itor = m_AttriPos.begin();
  while (!myFile.eof())
  {
    memset(m_StrBuf, 0, BUF_SIZE);
    myFile.getline(m_StrBuf, BUF_SIZE);

    m_PrePointer = m_StrBuf;
  
    //从数值开始存储统计数据;
    if (m_PrePointer[0] >= '0' && m_PrePointer[0] <= '9')
    {
      char *tempPtr = m_StrBuf; 
      CMyString tempTrafficType;
      while (!getTrafficType(tempPtr, tempTrafficType)) //如果有数据格式错误，便进行拼接;
      {
        char temBuf[BUF_SIZE] = {'\0'};
        myFile.getline(temBuf, BUF_SIZE);
        strcat_s(m_StrBuf, BUF_SIZE, temBuf);

        tempPtr = temBuf;
      }

      //开始截取需要的数据;
      itor = m_AttriPos.begin();
      ushort idx = 0; //对应属性值存储的位置;
      CMyString *tempDataArray = new CMyString[m_AttriNum];//用于临时存储各属性值里的需要的变量;
      ushort curAttriPos = 0; //当前属性值的位置;
      do  
      {
        if (curAttriPos == *itor) //所需要的属性;
        {
          sliceStr(m_PrePointer, tempDataArray[idx], ',', true);
          ++itor;
          ++idx;
        }
        else
          sliceStr(m_PrePointer, tempDataArray[idx], ',', false);
        ++curAttriPos;
      } while (itor != m_AttriPos.end());  //直到统计完所有属性值;
      
      CStatisticBayes::getInstance()->classifyData(tempDataArray, m_AttriNum, str2Enum(tempTrafficType)); //获得该行数据的网络类型;
      
      delete []tempDataArray;
    }  
  } //文件读取结束;

  m_PrePointer = NULL;
  myFile.close();
  
  CStatisticBayes::getInstance()->calcClassifyRate();  //计算分类混沌矩阵概率;

  return true;
}

bool CFileOperator::getTrafficType(const char *aBuf, CMyString &aTrafficType) const
{
  if (NULL == aBuf)
  { return false;}

  int continueCharNum = 0;    //获取连续的字符个数(必须大于三个才是网络类型);
  char tempChar[10] = {'\0'};
  while ((*aBuf) != '\0')
  {
    //第二个条件为P2P型流量设置;
    if ((*aBuf) <= 'Z' && (*aBuf) >= 'A' || ((*aBuf) == '2' && continueCharNum == 1))
    {
      tempChar[continueCharNum] = *aBuf;
      ++continueCharNum;
    }
    else
    {
      continueCharNum = 0;
    }
    if (continueCharNum == 3)
    {
      aTrafficType = tempChar;
      return true;
    }
    aBuf++;
  }

  return false;
}

ETrafficType CFileOperator::str2Enum(const CMyString &aStr)
{
  for (int idx = 0; idx < 9; ++idx)
  {
    if (INTERNET_TRAFFIC_TYPE[idx] == aStr)
    {
      return static_cast<ETrafficType>(idx);
    }
  }

  return ETT_ERR_TYPE;  
}

void CFileOperator::slot_operateFile(SDataPack aDatPack)
{
  switch (aDatPack.aFlag)
  {
  case EOF_Training:
    if (aDatPack.aFilePath != NULL && aDatPack.aSrcArray != NULL)
    {
      operateTrainingFile(aDatPack.aSrcArray, aDatPack.aSrcArraySize, aDatPack.aFilePath);
      emit signal_operateFinished(EOF_TrainingFinished);
    }
    break;
  case EOF_Classify:
    if (aDatPack.aFilePath != NULL)
    {
      operateClassifyFile(aDatPack.aFilePath);
      emit signal_operateFinished(EOF_ClassifyFinished); 
    }
    break;
  default:
     emit signal_operateFinished(EOF_NULL);
     break;
  }
}