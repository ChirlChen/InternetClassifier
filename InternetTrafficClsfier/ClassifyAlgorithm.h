#ifndef _CLASSIFYALOGRITHM_H_
#define _CLASSIFYALOGRITHM_H_

#include <vector>
#include "SingleTon.h"
#include "BayesAlgorithm.h"

class CMyString;
template<class Key, class Value> class CContainer;

/******************************************
类说明：统计法贝叶斯算法类，统计数据包中各网络流量类型、各类型对应的属性的值等，然后用于计算网络包的分类;
*******************************************/
class CStatisticBayes : public CSingleTon<CStatisticBayes>, public CBayesAlgorithm
{
public:
  CStatisticBayes(void);
  ~CStatisticBayes(void);

private:
  CStatisticBayes(const CStatisticBayes &){}
  CStatisticBayes &operator=(const CStatisticBayes &){}

public:
  void calcStatisticRate();
  void calcTrainingRate();    //计算使用统计法得到的数据的概率;
  void classifyData(const CMyString *aDataArray, int aArraySize, const ETrafficType aTrafficType);  //使用统计法分类;
  bool statisticAllTypeAttri(const ETrafficType aTrafficType, const uint &aAttri, const CMyString &aKey);   //统计各网络流量类型的对应属性各值出现次数;
  bool statisticTrafficType(const ETrafficType aTrafficType); //统计网络流量类型数据;
  void mallocMemory4AllTypeAttri(const int aSize);

 CContainer<CMyString, float> ***getAllTypeAttriRate() const;
  CContainer<CMyString, uint> ***getAllTypeAttri() const;
  
  //清理容器内数据;
  void clearAll();
  void clearTrainingData();

private:
  CContainer<CMyString, uint> ***m_AllTypeAttri; //统计所有网络流量类型各自对应的各属性的值数量;
  CContainer<CMyString, float> ***m_AllTypeAttriRate; //统计所有网络流量类型各自对应的各属性的值数量的概率;
};

/******************************************
类说明：正态分布法贝叶斯算法类，统计数据包中各网络流量类型数量、各类型对应的属性的值的出现次数的均值，方差等，然后用于计算网络包的分类;
*******************************************/
class CGuassianBayes : public CSingleTon<CGuassianBayes>, public CBayesAlgorithm
{
public:
protected:
private:
};




#endif
