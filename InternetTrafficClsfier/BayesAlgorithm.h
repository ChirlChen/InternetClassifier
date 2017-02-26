#ifndef _BAYESALGORITHM_H_
#define _BAYESALGORITHM_H_

#include "DataStructDef.h"
#include "MacroDef.h"

typedef unsigned int uint;

class CBayesAlgorithm 
{
public:
  CBayesAlgorithm(void);
  ~CBayesAlgorithm(void);
 
  virtual void clearTrainingData() = 0;

  float calcProbablity(const float &aTatalNum, const float &aTargetNum); //计算概率（aTargetNum/aTatalNum）;
  void calcClassifyRate();  //计算分类成功概率;
  
  void clearClassifyData();
  float getTrafficTypeRate(int aX) const;
  uint getClassifyResultArray(int aX, int aY) const;
  uint getTrafficType(int aX) const;
  void setClassifyResultRateArray(const int &aX, const int &aY, const float &aProbablity);
  float getClassifyResultRateArray(int aX, int aY) const;

  static int getClassifyTimes();

protected:
  uint m_TrafficType[ETT_ALL_TYPE + 1];  //统计各网络流量类型数量的容器;
  float m_TrafficTypeRate[ETT_ALL_TYPE + 1]; //统计各网络流量类型数量的概率的容器;
  uint m_ClassifyResultArray[TRAFFIC_TYPE_NUM_O][TRAFFIC_TYPE_NUM_C]; //网络流量原始类型分类到各类型的数量（混沌矩阵）;
  float m_ClassifyResultRateArray[TRAFFIC_TYPE_NUM_O][TRAFFIC_TYPE_NUM_C];  //网络流量原始类型分类到各类型的概率（混沌矩阵）;

  DEFSETGET(AttriNum, int, protected); //属性数量;
  DEFSETGET(isClassifyResultEmpty, bool, protected);   //分类结果是否为空;

  static int m_ClassifyTimes;   //标记当前是第几次分类的结果;
};

#endif