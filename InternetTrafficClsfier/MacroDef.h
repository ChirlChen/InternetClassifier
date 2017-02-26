#ifndef _MACRODEF_H_
#define _MACRODEF_H_

#include <stddef.h>

/******************宏定义****************/
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))

//定义类中指针成员变量的get和set参数函数;
/*注意：set函数只是简单的浅拷贝;*/
#define DEFSETGET(_NAME_, _TYPE_, _ACCESS_RIGHT_) \
_ACCESS_RIGHT_: \
  _TYPE_ m_##_NAME_; \
public: \
  _TYPE_ get##_NAME_(void) const\
{ \
  return m_##_NAME_; \
  }\
  void set##_NAME_(_TYPE_ (aData)) \
{ \
  m_##_NAME_ = (aData); \
  }

//判断传入的指向单个对象的指针是否为空，不为空则delete;
#define IF_NOT_NULL_DELETE_s(_Data_) if (NULL != (_Data_)){delete (_Data_);}
//判断传入的指向对象数组的指针是否为空，不为空则delete;
#define IF_NOT_NULL_DELETE_a(_Data_) if (NULL != (_Data_)){delete [](_Data_);}

#endif