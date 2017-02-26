#include "StrOperator.h"
#include "MacroDef.h"
#include "debug_new.h"
#include <assert.h>

CStrOperator::CStrOperator()
{

}

CStrOperator::~CStrOperator()
{
  
};

int CStrOperator::str2int(const char *aStr)
{
  if (aStr == NULL)
  {
    return -1;   
  }

  char tempChar[10] = {'\0'};
  int loop = 0;
  while(loop < 10 && aStr[loop] >= '0' && aStr[loop] <= '9')  //将数字取出;
  {
    tempChar[loop] = aStr[loop];
    loop++;
  }

  int tempInt = 0;
  int index = 1;   //各整数位的系数;
  while(loop > 0) //转换为整数;
  {
    loop--;
    tempInt += (tempChar[loop] - '0') * index;
    index = index * 10;
  }

  return tempInt;
}

unsigned short CStrOperator::str2ushort(const char *aStr)
{
  if (aStr == NULL)
  {
    return -1;   
  }

  char tempChar[5] = {'\0'};
  int loop = 0;
  while(loop < 5 && aStr[loop] >= '0' && aStr[loop] <= '9')  //将数字取出;
  {
    tempChar[loop] = aStr[loop];
    loop++;
  }

  unsigned short tempUShort = 0;
  int index = 1;   //各整数位的系数;
  while(loop > 0) //转换为整数;
  {
    loop--;
    tempUShort += (tempChar[loop] - '0') * index;
    index = index * 10;
  }

  return tempUShort;
}

float CStrOperator::str2float(const char *aStr)
{
  return 0.1f;
}

bool CStrOperator::str2bool(const char *aStr)
{
  return true;
}
