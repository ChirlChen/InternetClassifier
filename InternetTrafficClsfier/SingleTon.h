#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "debug_new.h"

template <class ClsName>
class CSingleTon
{
public:
  CSingleTon();
  virtual ~CSingleTon();

  static ClsName *getInstance();
  static void destroyInstance();

private:
  class CDeleter
  {
  public: 
    ~CDeleter();
  };
  static CDeleter m_Deleter;
private:
  static ClsName *m_Instance;
};

template <class ClsName>
CSingleTon<ClsName>::CDeleter::~CDeleter()
{
  if (NULL != CSingleTon::m_Instance)
  {
    delete m_Instance;
    m_Instance = NULL;
   }
}

template <class ClsName>
CSingleTon<ClsName>::CSingleTon()
{
}

template <class ClsName>
CSingleTon<ClsName>::~CSingleTon()
{
  
}

template <class ClsName>
ClsName *CSingleTon<ClsName>::m_Instance = NULL;

template <class ClsName>
ClsName *CSingleTon<ClsName>::getInstance()
{
  if (NULL == m_Instance)
  {
    m_Instance = new ClsName;
  }
  return m_Instance;
}

template <class ClsName>
void CSingleTon<ClsName>::destroyInstance()
{
  if (NULL != m_Instance)
  {
    delete m_Instance;
    m_Instance = NULL;
  }
}
#endif