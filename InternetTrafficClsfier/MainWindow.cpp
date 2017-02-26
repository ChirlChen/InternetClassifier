#include "MainWindow.h"
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "ClassifyAlgorithm.h"
#include "ClassifyWin.h"
#include "ResultWin.h"
#include "TabWidget.h"
#include "DataStructDef.h"
#include "debug_new.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_ui(new Ui_CMainWindow)
{
  initLocalVar();
  initConnect();
}

CMainWindow::~CMainWindow()
{
  if (NULL != m_ui)
  {
    delete m_ui;
  }
  CTabWidget::destroyInstance();
  CStatisticBayes::destroyInstance();
}

void CMainWindow::initLocalVar()
{
  m_ui->setupUi(this);

  setCentralWidget(CTabWidget::getInstance());

  QLabel *version = new QLabel(m_ui->statusBar);
  QString tempVersion = "v:";
  tempVersion.append(MY_VERSION.data());
  version->setText(tempVersion);//版本信息;
}

void CMainWindow::initConnect() const
{
  connect(m_ui->actionBegin, SIGNAL(triggered()),
          this, SLOT(slot_clickClsBegin()));

  connect(m_ui->actionShow, SIGNAL(triggered()),
          this, SLOT(slot_clickRltShowProbablity()));

  connect(m_ui->action_2, SIGNAL(triggered()),
          this, SLOT(slot_clickRltShowNum()));

  connect(m_ui->actionExit, SIGNAL(triggered()),
    this, SLOT(slot_exit()));
}


//控制为只能产生一个分类标页;
void CMainWindow::slot_clickClsBegin()
{
  CClassifyWin *temp = NULL; //用于传递CClassifyWin类的类型;
  int classifyIndex = CTabWidget::getInstance()->ifWidgetExist(temp);
  if (classifyIndex >= 0)  //已经有了分类标签页;
  {
    CTabWidget::getInstance()->slot_CloseTab(classifyIndex);
  }
  CTabWidget::getInstance()->newTab(new CClassifyWin, "classifier");
}

void CMainWindow::slot_clickRltShowProbablity()
{
  if (CStatisticBayes::getInstance()->getisClassifyResultEmpty())
  {
    QMessageBox::warning(this, tr("Warning"),
        tr("Please open \"Training Set\" to train the algorithm first! \n or \n"
            "Open a \"Classify Set\" to classify.Then you can show the result!"),
        QMessageBox::Ok);
    return;
  }
  char buf[16] = {0};
  sprintf(buf,"result_P%d",CStatisticBayes::getClassifyTimes());
  QString tabName = buf;
  
  if (CTabWidget::getInstance()->ifWidgetExist(tabName))
  {
    std::string tempStr = "The Tab \'";
    tempStr.append(buf);
    tempStr.append("\' is already Exist!!");
    QMessageBox::warning(this, tr("Warning"),
      tr(tempStr.data()),
      QMessageBox::Ok);
  }
  else
    CTabWidget::getInstance()->newTab(new CResultWin(CResultWin::ESRT_Probablity), tabName);
}

void CMainWindow::slot_clickRltShowNum()
{
  if (CStatisticBayes::getInstance()->getisClassifyResultEmpty())
  {
    QMessageBox::warning(this, tr("Warning"),
      tr("Please open \"Training Set\" to train the algorithm first! \n or \n"
      "Open a \"Classify Set\" to classify.Then you can show the result!"),
      QMessageBox::Ok);
    return;
  }
  char buf[16] = {0};
  sprintf(buf,"result_N%d",CStatisticBayes::getClassifyTimes());
  QString tabName = buf;

  if (CTabWidget::getInstance()->ifWidgetExist(tabName))
  {
    std::string tempStr = "The Tab \'";
    tempStr.append(buf);
    tempStr.append("\' is already Exist!!");
    QMessageBox::warning(this, tr("Warning"),
      tr(tempStr.data()),
      QMessageBox::Ok);
  }
  else
    CTabWidget::getInstance()->newTab(new CResultWin(CResultWin::ESRT_Number), tabName);
}

void CMainWindow::slot_exit()
{
  this->close();
}