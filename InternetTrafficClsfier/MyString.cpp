#include "MyString.h"
#include "MacroDef.h"
#include <cstring>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "debug_new.h"


CMyString::CMyString(void)
  : m_BufSize(PRIMER_STR_LEN),
    m_StrSize(0),
    m_Buf(new char[m_BufSize])
{
  memset(m_Buf, 0, m_BufSize);
}

CMyString::CMyString(const char *aStr)
  : m_BufSize(PRIMER_STR_LEN),
    m_StrSize(0),
    m_Buf(new char[m_BufSize])  
{
  if (NULL == aStr)
  { return;}

  memset(m_Buf, 0, m_BufSize);
  int needLen = strlen(aStr) + 1;
  if ((m_BufSize - m_StrSize) < needLen)
  {
    resizeBuf(needLen + m_BufSize);
  }

  covery(aStr);
}

CMyString::CMyString(const CMyString &aStr)
 : m_BufSize(0),
   m_StrSize(0),
   m_Buf(NULL)
{
  m_BufSize = aStr.getStrSize() + 1;
  m_Buf = new char[m_BufSize];

  covery(aStr.getBuf());
}

CMyString::~CMyString(void)
{
  IF_NOT_NULL_DELETE_a(m_Buf);
}

bool CMyString::operator()(const CMyString &aStr1, const CMyString &aStr2) const
{ 
  return aStr1 < aStr2;
}

bool CMyString::operator<(const CMyString &aStr) const  //用于比较两个数值型字符串的大小;
{
//  return calcStrValue(m_Buf) < calcStrValue(aStr.getBuf()); //实现方式1;
  
  //实现方式2;(实验证明方式二略优);
  if (m_StrSize != aStr.getStrSize()) //由于用于比较的数都是同类型的，要不是整数，要不就是整数位相同的小数，所以这里就简单处理了;
  {
    return m_StrSize < aStr.getStrSize();
  }
  for (int idx = 0; idx < m_StrSize && idx < aStr.getStrSize(); ++idx)
  {
    if (m_Buf[idx] < aStr.getBuf()[idx])
    {
      return true;
    }
    else if (m_Buf[idx] > aStr.getBuf()[idx])
    {
      return false;
    }
  }//比较完两者拥有的共同长度下所有字符，都相等;

  return false;
}

CMyString &CMyString::operator=(const CMyString &aStr)
{
  m_BufSize = aStr.getBufSize();
  m_Buf = new char[m_BufSize];

  covery(aStr.getBuf());
  return *this;
}

CMyString &CMyString::operator=(const char *aStr)
{
  int needLen = strlen(aStr) + 1;
  if (m_BufSize < needLen)
  {
    setBufSize(needLen);
    delete []m_Buf;
    m_Buf = new char[needLen];
    m_BufSize = needLen;
  }
  covery(aStr);

  return *this;
}

bool CMyString::operator==(const char *aStr) const 
{
  if (aStr == NULL)
    return false;

  int strLen = Min(m_StrSize, strlen(aStr));
  strLen = Min(strLen, 3) - 1;

  while (strLen >= 0)
  {
    if (m_Buf[strLen] != aStr[strLen])
    {
      return false;
    }
    else
      --strLen;
  }
  return true;
}

bool CMyString::operator==(const CMyString &aStr) const
{
  char *p = aStr.getBuf();
  for (int idx = 0; idx < 3; ++idx)
  {
    if (m_Buf[idx] != p[idx])
    {
      return false;
    }
  }

  return true;
}

bool CMyString::append(const char *aStr)
{
  int strLen = strlen(aStr) + 1;  
  if (strLen < (m_BufSize - m_StrSize))
  {
    resizeBuf(strLen + m_BufSize);
  }
  strcat(m_Buf, aStr);
  m_StrSize += strLen - 1;

  return true;
}

bool CMyString::append(const char aChar)
{
  if ((m_BufSize - m_StrSize) < 2)
  {
    resizeBuf(1 + m_BufSize);
  }
  m_Buf[m_StrSize++] = aChar;
  m_Buf[m_StrSize] = '\0';

  return true;
}

int CMyString::calcStrValue(const char *aStr) const
{
  int ret = 0;
  char *tempPtr = aStr ? const_cast<char *>(aStr) : m_Buf;
  while ((*tempPtr) != '\0')
  {
    ret += (*tempPtr);
    ++tempPtr;
  }

  return ret;
}

char *CMyString::resizeBuf(const int &aNeedStrLen)
{
  char *tempPtr = m_Buf;
  if (aNeedStrLen < MAX_STR_LEN)
  {
    setBufSize(aNeedStrLen * 2);
  }
  else
    setBufSize(m_BufSize + MAX_STR_LEN);
  
  m_Buf = new char[m_BufSize];
  memset(m_Buf, 0, m_BufSize);
  memcpy_s(m_Buf, m_BufSize, tempPtr, m_StrSize);
  delete []tempPtr;
  
  return m_Buf;
}

bool CMyString::covery(const char *aStr)
{
  int strLen = strlen(aStr) + 1;  
  if (strLen > m_BufSize)
  {
    resizeBuf(strLen);
  }
  else
    memset(m_Buf, 0, m_BufSize);
  strcpy(m_Buf, aStr);
  m_StrSize = strLen - 1;

  return true;
}

void CMyString::clearData()
{
  if (m_StrSize > 0)
  {
    memset(m_Buf, 0, m_StrSize);
    m_StrSize = 0;
  }
}

bool CMyString::empty() const
{
  if (m_StrSize == 0)
  {
    return true;
  }
  else
    return false;
}