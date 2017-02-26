#ifndef _FILEOPERATOR_H_
#define _FILEOPERATOR_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <QObject>
#include "MacroDef.h"  
#include "DataStructDef.h"

typedef unsigned int uint;
typedef unsigned short ushort;

class CMyString;
class CStatisticBayes;

class CFileOperator : public QObject
{
  Q_OBJECT
public:
  CFileOperator(QObject *aParent = 0);
  ~CFileOperator(void);

private:
  CFileOperator(const CFileOperator &);
  CFileOperator &operator=(const CFileOperator &);

public:
  void statisticData();
  bool operateTrainingFile(ushort *aSrcArray, const int &aSize, const char *aFilePath = NULL); //aFilePath为操作文件的路径,aSrcArray为勾选的属性值，aSize为属性值个数;

  bool operateClassifyFile(const char *aFilePath = NULL); //aFilePath为操作文件的路径,aSrcArray为勾选的属性值，aSize为属性值个数;
  bool setAttriPosArray(std::ifstream &aMyFile, ushort *aSrcArray, const int &aSize);
  const std::vector<ushort> &getAttriPos();

public slots:
  void slot_operateFile(SDataPack aDataPack);

protected:
  bool getTrafficType(const char *aBuf, CMyString &aTrafficType) const;
  CMyString &sliceStr(const char *aSrc, CMyString &aDest, const char aChar, bool aIsNeedTheData);//aChar为分隔符, aIsNeedTheData为是否需要该数据的标志;
  EPickOutAttriResult pickOutAttriNum(const char *aStr, ushort &aTargetNum);  //选出需要的属性所处位置;
  ETrafficType str2Enum(const CMyString &aStr);

signals:
  void signal_operateFinished(EOperateFlag aFlag);

  DEFSETGET(PrePointer, char *, private); //m_prePointer用于保存当前指针位置;
  DEFSETGET(StrBuf, char *, private); //m_StrBuf用于缓存从文档中读取的一行数据;
  DEFSETGET(FilePath, char *, private);   //文件路径;

private:
  static short m_AttriNum; //属性值的个数;
  static std::vector<ushort> m_AttriPos; //存储属性值的位置;
};



#endif
