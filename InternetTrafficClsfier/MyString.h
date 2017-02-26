#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include "MacroDef.h"

const int MAX_STR_LEN = 1000;  //string的最大缓存大小;
const int PRIMER_STR_LEN = 8;  //初始字符串长度;
class CMyString
{
public:
  CMyString();
  CMyString(const char *aStr);
  CMyString(const CMyString &aStr);
  ~CMyString(void);
  
  bool operator()(const CMyString &aStr1, const CMyString &aStr2) const;
  bool operator<(const CMyString &aStr) const;
  CMyString &operator=(const CMyString &aStr);
  CMyString &operator=(const char *aStr);
  bool operator==(const char *aStr) const;
  bool operator==(const CMyString &aStr) const;
  bool append(const char *aStr);  //在字符串后面追加字符;
  bool append(const char aChar);
  int calcStrValue(const char *aStr = NULL) const;   //计算str的总值;
//  int calcStrValue(const CMyString &aStr) const;
  void clearData(); //清除m_Data里面的数据;
  bool empty() const;
private:
  bool covery(const char *aStr);  //用新字符串覆盖以前的字符串;
  char *resizeBuf(const int &aNeedStrLen);  //重新分配m_Buf的大小;
  
  DEFSETGET(BufSize, int, private); //string类的总空间大小;
  DEFSETGET(StrSize, int, private); //string类已保存的字符串大小;
  DEFSETGET(Buf, char *, private);  //string类的缓存字符串的空间;
};


#endif
