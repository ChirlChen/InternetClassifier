#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <map>

typedef unsigned int uint;

enum EInsertResult //插入返回结果;
{
  EIR_NewKey,     //无该键值;
  EIR_OldKey,     //已经存在该键值;
  EIR_ERROR,      //插入失败;
};

/******************************************
类说明：用于处理网络流量包的特定容器（类似于map，相当于map的各key值出现次数的计数器）;
     当在数据包中读取某类型数据时：;
     每读取到该类型中一个新的值，则在容器中插入该新值（key），并将该值对应的value值默认设为1;
     每读到一次该类型已存在的值，则将该值后面的value值默认加1;
*******************************************/
template<class Key, class Value>
class CContainer  
{
public:
  CContainer(void);
  ~CContainer(void);

  bool empty() const;
  std::map<Key, Value> *getMyData() const { return m_MyData;}
  EInsertResult insert(const Key &aKey, const Value &aValue); 
  Value find(const Key &aKey) const;   //查找指定键值，成功返回该键对应的值，否则返回0;
  Value operator[](const Key &aKey) const;

private://禁止拷贝及赋值;
  CContainer(const CContainer &){}
  CContainer& operator=(const CContainer &){}
  
private:
  std::map<Key, Value> *m_MyData;//定义m_MyData变量，为数据容器;
};


template<class Key, class Value>
CContainer<Key, Value>::CContainer(void)
  : m_MyData(new std::map<Key, Value>)
{
}

template<class Key, class Value>
CContainer<Key, Value>::~CContainer(void)
{
  if (NULL != m_MyData)
  {
    delete m_MyData;
  }
}

template<class Key, class Value>
bool CContainer<Key, Value>::empty() const
{
  return m_MyData->empty();
}


template<class Key, class Value>
EInsertResult CContainer<Key, Value>::insert(const Key &aKey, const Value &aValue)
{
  if (!aValue)
  { return EIR_ERROR;}

  Value currentNum = find(aKey);
  if (Value(0.00001) != currentNum)   //如果已经存在该Key值，则将该Key所对应的键值加aValue;
  {
    currentNum += aValue;
    (m_MyData->find(aKey))->second = currentNum;
    return EIR_OldKey;
  }
  else
  {
    m_MyData->insert(std::map<Key, Value>::value_type(aKey, aValue));

    return EIR_NewKey;
  }
}

template<class Key, class Value>
Value CContainer<Key, Value>::find(const Key &aKey) const
{
  std::map<Key, Value>::iterator itor;
  itor = m_MyData->find(aKey);

  if (itor == m_MyData->end())
    return Value(0.00001);  //这里的一个极小数是为了优化贝叶斯算法当前统计模型里某值的概率不存在时，以一个极小值代替0，减小算法分类误差;
  else
  {
    return itor->second;
  }
}

template<class Key, class Value>
Value CContainer<Key, Value>::operator[](const Key &aKey) const
{
  return find(aKey);
}


#endif