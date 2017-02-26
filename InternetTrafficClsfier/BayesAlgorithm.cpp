#include "BayesAlgorithm.h"
#include "MacroDef.h"
#include "debug_new.h"
#include <assert.h>

int CBayesAlgorithm::m_ClassifyTimes = 0;
CBayesAlgorithm::CBayesAlgorithm(void)
  : m_AttriNum(0),
    m_isClassifyResultEmpty(true)
{
  clearClassifyData();  //清空分类容器里的值;
  for (int idx = 0; idx < TRAFFIC_TYPE_NUM_O; ++idx)
  {
    m_TrafficType[idx] = 0;
    m_TrafficTypeRate[idx] = 0; 
  }
}

CBayesAlgorithm::~CBayesAlgorithm(void)
{ 
}

float CBayesAlgorithm::calcProbablity(const float &aTatalNum, const float &aTargetNum)
{
  if (aTatalNum == 0.0f)
  {
    if (aTatalNum == 0.0f)
    {
      return 0.0f;
    }

    return 1.0f;
  }

  if (aTatalNum < aTargetNum)
  {
    return -1.0f;
  }
   
  return float (aTargetNum / aTatalNum);
}

void CBayesAlgorithm::clearClassifyData()
{
  for (int idx = 0; idx <= ETT_ALL_TYPE; ++idx)
  {
    for (int loop = 0; loop <= ETT_ALL_TYPE; ++loop)
    {
      m_ClassifyResultArray[idx][loop] = 0;
      m_ClassifyResultRateArray[idx][loop] = 0;
    }
  }
  m_isClassifyResultEmpty = true;
}

void CBayesAlgorithm::calcClassifyRate()
{
  for (int OriginalTypeIdx = 0; OriginalTypeIdx <= ETT_ALL_TYPE; ++OriginalTypeIdx)
  {
    for (int ClassifyTypeIdx = 0; ClassifyTypeIdx <= ETT_ALL_TYPE; ++ClassifyTypeIdx)
    {
      float TypeTotalNum = m_ClassifyResultArray[OriginalTypeIdx][ETT_ALL_TYPE];
      float ClassifyNum = m_ClassifyResultArray[OriginalTypeIdx][ClassifyTypeIdx];
      float Probablity = 0.0f;

      if (TypeTotalNum == 0.0f)
      {
        Probablity = 0.0f;
      }
      else
        Probablity = ClassifyNum / TypeTotalNum;

      m_ClassifyResultRateArray[OriginalTypeIdx][ClassifyTypeIdx] = Probablity;
    }
  }
  m_isClassifyResultEmpty = false;
  ++m_ClassifyTimes;
}

float CBayesAlgorithm::getClassifyResultRateArray(int aX, int aY) const
{
  return m_ClassifyResultRateArray[aX][aY];
}

float CBayesAlgorithm::getTrafficTypeRate(int aX) const
{
  return m_TrafficTypeRate[aX];
}

uint CBayesAlgorithm::getClassifyResultArray(int aX, int aY) const
{
  if (aX < 0 || aX >= TRAFFIC_TYPE_NUM_O || aY < 0 || aY >= TRAFFIC_TYPE_NUM_C)
    return 0;
  return m_ClassifyResultArray[aX][aY];
}

uint CBayesAlgorithm::getTrafficType(int aX) const
{
  return m_TrafficType[aX];
}

void CBayesAlgorithm::setClassifyResultRateArray(const int &aX, const int &aY, const float &aProbablity)
{
  if (aX < 0 || aX >= TRAFFIC_TYPE_NUM_O || aY < 0 || aY >= TRAFFIC_TYPE_NUM_C)
    return ;

  m_ClassifyResultRateArray[aX][aY] = aProbablity;
}

int CBayesAlgorithm::getClassifyTimes()
{
  return m_ClassifyTimes;
}


