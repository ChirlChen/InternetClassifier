#include "ResultWin.h"
#include "ClassifyAlgorithm.h"

CResultWin::CResultWin(EShowResultType aType /*= ESRT_Probablity*/, QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);

  showClassifyResult(aType);
}

CResultWin::~CResultWin()
{

}

void CResultWin::showClassifyResult(EShowResultType aType)
{
  if (CStatisticBayes::getInstance() == NULL)
  {
    return;
  }

  int tempColumn = TRAFFIC_TYPE_NUM_O;
  int tempRow = TRAFFIC_TYPE_NUM_C;

  ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui.tableWidget->setAlternatingRowColors( true );  
  ui.tableWidget->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);"   
    "alternate-background-color: rgb(141, 163, 215);}");  

  ui.tableWidget->setColumnCount(tempColumn - 1); 
  ui.tableWidget->setRowCount(tempRow); 
  QStringList Hheaders, Vheaders;
  
  Hheaders << "WWW" << "FTP" << "MAIL" << "P2P" << "ATTACK" << "DATABASE" 
          << "SERVICES" << "INTERACTIVE" << "MULTIMEDIA" << "OTHER_TYPE";
  Vheaders << "WWW" << "FTP" << "MAIL" << "P2P" << "ATTACK" << "DATABASE" 
          << "SERVICES" << "INTERACTIVE" << "MULTIMEDIA" << "OTHER_TYPE" << "TOTAL_NUM";
  ui.tableWidget->setHorizontalHeaderLabels(Hheaders); 
  ui.tableWidget->setVerticalHeaderLabels(Vheaders);

  for (int idx = 0;idx < Hheaders.length();++idx) 
  {
#if QT_VERSION >= 0x050000
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(idx, QHeaderView::Stretch);
#else
    ui.tableWidget->horizontalHeader()->setResizeMode(idx, QHeaderView::Stretch);
#endif
  }

  if (aType == ESRT_Probablity)
  {
    showProbablity(tempColumn, tempRow);
  }
  else
    showNumber(tempColumn, tempRow);
}

void CResultWin::showProbablity(int &aColumn, int &aRow)
{
  if (CStatisticBayes::getInstance() == NULL)
  { return;}

  for ( int curColumn = 0; curColumn < aColumn - 1; ++curColumn)
  {
    for (int curRow = 0; curRow < aRow - 1; ++curRow)
    {
      float tempData = CStatisticBayes::getInstance()->getClassifyResultRateArray(curColumn, curRow);
      char tempStr[10] = {'\0'};
      sprintf(tempStr, "%0.5f", tempData);
      ui.tableWidget->setItem(curRow, curColumn, new QTableWidgetItem(QString(tempStr))); 
      if (curColumn == curRow)
      {
        ui.tableWidget->item(curRow, curColumn)->setTextColor(QColor(255, 51, 50));
      }
    }
    uint tempData = CStatisticBayes::getInstance()->getClassifyResultArray(curColumn, ETT_ALL_TYPE);
    char tempStr[10] = {'\0'};
    sprintf(tempStr, "%d", tempData);
    ui.tableWidget->setItem(ETT_ALL_TYPE, curColumn, new QTableWidgetItem(QString(tempStr))); 
  }
}

void CResultWin::showNumber(int &aColumn, int &aRow)
{
  if (CStatisticBayes::getInstance() == NULL)
  { return;}

  for ( int curColumn = 0; curColumn < aColumn - 1; ++curColumn)
  {
    for (int curRow = 0; curRow < aRow; ++curRow)
    {
      uint tempData = CStatisticBayes::getInstance()->getClassifyResultArray(curColumn, curRow);
      char tempStr[10] = {'\0'};
      sprintf(tempStr, "%d", tempData);
      ui.tableWidget->setItem(curRow, curColumn, new QTableWidgetItem(QString(tempStr))); 
      if (curColumn == curRow)
      {
        ui.tableWidget->item(curRow, curColumn)->setTextColor(QColor(255, 50, 50));
      }
    }
  }
}