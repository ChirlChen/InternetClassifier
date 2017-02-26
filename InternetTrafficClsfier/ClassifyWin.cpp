#include "ClassifyWin.h"
#include "ui_ClassifyWin.h"
#include "DataStructDef.h"
#include "TabWidget.h"
#include "MacroDef.h"
#include "ClassifyAlgorithm.h"
#include "ResultWin.h"
#include "WaitDialog.h"
#include "debug_new.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QThread>

#define _TEST_FOR_SOME_HEARDER_ 0
//those header here is for test;
#if _TEST_FOR_SOME_HEARDER_
  #include "ClassifyAlgorithm.h"
  #include "BayesAlgorithm.h"
  #include "MyString.h"
  #include "StrOperator.h"
#endif

CClassifyWin::CClassifyWin(QWidget *parent)
    : QWidget(parent),
      m_Ui(new Ui_CClassifyWin),
      m_CheckBoxGroup(new QButtonGroup(this)),
      m_AllCheckedBox(new unsigned short[ATTRI_CHECKBOX_NUM]),
      m_CheckedBoxNum(0),
      m_FileOperator(new CFileOperator),
      m_IsTrained(false),
      m_destPath(NULL),
      m_waitDialog(new CWaitDialog(this))
{
  m_Ui->setupUi(this);

  memset(m_AllCheckedBox, 0, ATTRI_CHECKBOX_NUM);
 
  //线程操作部分;
  m_WorkThread = new QThread;
  m_FileOperator->moveToThread(m_WorkThread);

  connect(this, SIGNAL(signal_SendData(SDataPack)),
          m_FileOperator, SLOT(slot_operateFile(SDataPack)));
  connect(m_FileOperator, SIGNAL(signal_operateFinished(EOperateFlag)),
          this, SLOT(slot_operateFinished(EOperateFlag)));  
 // m_WorkThread->start();

  setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
  
  connect(m_Ui->pushButton, SIGNAL(clicked(bool)),
          this, SLOT(slot_openTrainingSet(bool)));
  connect(m_Ui->pushButton_2, SIGNAL(clicked(bool)),
          this, SLOT(slot_openClassifySet(bool)));
  connect(m_Ui->pushButton_3, SIGNAL(clicked(bool)),
          this, SLOT(slot_beginClassify(bool)));
  connect(m_Ui->pushButton_4, SIGNAL(clicked(bool)),
          this, SLOT(slot_beginTraining(bool)));        
  
  m_Ui->lineEdit->setReadOnly(true);
  m_Ui->lineEdit_2->setReadOnly(true);

#if _TEST_FOR_SOME_HEARDER_
  test();
#endif
}

CClassifyWin::~CClassifyWin()
{
  IF_NOT_NULL_DELETE_s(m_FileOperator);
  IF_NOT_NULL_DELETE_a(m_AllCheckedBox);
  IF_NOT_NULL_DELETE_s(m_Ui);  
  IF_NOT_NULL_DELETE_a(m_destPath);
  IF_NOT_NULL_DELETE_s(m_waitDialog);
  if (!m_WorkThread->isFinished())
  {
    m_WorkThread->quit();
  }
  
  IF_NOT_NULL_DELETE_s(m_WorkThread);
}

void CClassifyWin::addAllCheckBox2Group() const
{
  m_CheckBoxGroup->addButton(m_Ui->checkBox, ECBON_CheckBox0);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_2, ECBON_CheckBox2);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_3, ECBON_CheckBox3);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_4, ECBON_CheckBox4);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_5, ECBON_CheckBox5);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_6, ECBON_CheckBox6);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_7, ECBON_CheckBox7);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_8, ECBON_CheckBox8);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_9, ECBON_CheckBox9);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_10, ECBON_CheckBox10);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_11, ECBON_CheckBox11);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_12, ECBON_CheckBox12);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_13, ECBON_CheckBox13);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_14, ECBON_CheckBox14);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_15, ECBON_CheckBox15);
  m_CheckBoxGroup->addButton(m_Ui->checkBox_16, ECBON_CheckBox16);
}

void CClassifyWin::findOutAllCheckedBox()
{
  m_CheckedBoxNum = 0;
  memset(m_AllCheckedBox, 0, ATTRI_CHECKBOX_NUM);
  int idx = 0;    //数组下标，被传入到RecordChoosedCheckbox()函数中修改（设计有些不太合理）;
  //逐一检查各CheckBox是否被勾选;

  recordChoosedCheckBox(m_Ui->checkBox, idx);
  recordChoosedCheckBox(m_Ui->checkBox_11,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_2,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_10,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_3,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_4,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_5,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_6,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_7,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_15,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_16,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_8,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_13,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_12,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_14,  idx);
  recordChoosedCheckBox(m_Ui->checkBox_9,  idx);

}

bool CClassifyWin::recordChoosedCheckBox(QCheckBox *checkBox, int &idx)
{
  if (NULL == checkBox && (idx < 0 || idx >= ATTRI_CHECKBOX_NUM))
  {return false;}

  //如果该checkBox被钩选，则记录下该checkBox的属性号;
  if (checkBox->isChecked())
  {
    m_AllCheckedBox[idx] = checkBox->text().toUShort();
    ++idx;
    ++m_CheckedBoxNum;    //被勾选的checkbox数加1;
    return true;
  }
  else
    return false;
}

bool CClassifyWin::savePath(QLineEdit *aLineEdit)
{
  if (NULL == aLineEdit)
  {return false;}

  QString filename;
  filename = QFileDialog::getOpenFileName(this,
              tr("ChoseFilePath"),
              "",
              tr("Txt files (*.arff)")); //选择路径;
  if (filename.size() == 0)
  { return false;}
  
  //保存路径;
  aLineEdit->setText(filename);
  return true;
}

char *CClassifyWin::QString2ToStr(QString &aQStr)
{
  if (aQStr.isEmpty())
  { return false;}

  if (m_destPath != NULL)
  {
    delete []m_destPath;
    m_destPath = NULL;
  }

  QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
  QByteArray ba = aQStr.toLocal8Bit();
  m_destPath = new char[strlen(ba.data()) + 1];
  if (m_destPath == NULL)
  {
    return NULL;
  }
  strcpy(m_destPath, ba.data());

  return m_destPath;
}

inline bool CClassifyWin::showPathInLineEdit(QLineEdit *aLineEdit, const char *aPath)
{
  if (NULL == aLineEdit)
  {return false;}

  if (aPath != NULL)
  {
    //显示中文设置;
    QString myFilePath = QString::fromLocal8Bit(aPath);
    aLineEdit->setAlignment(Qt::AlignLeft);
    aLineEdit->setText(myFilePath);
 
    return true;
  }
  else 
  {
    aLineEdit->setPlaceholderText("Open Failed!!! Please Retry!");
    return false;
  }
}

void CClassifyWin::slot_clickedCheckBox() const
{
  switch(m_CheckBoxGroup->checkedId())
  {
  case ECBON_CheckBox0:

    break;
  case ECBON_CheckBox2:
    break;
  case ECBON_CheckBox3:
    break;
  case ECBON_CheckBox4:
    break;
  case ECBON_CheckBox5:
    break;
  case ECBON_CheckBox6:
    break;
  case ECBON_CheckBox7:
    break;
  case ECBON_CheckBox8:
    break;
  case ECBON_CheckBox9:
    break;
  case ECBON_CheckBox10:
    break;
  case ECBON_CheckBox11:
    break;
  case ECBON_CheckBox12:
    break;
  case ECBON_CheckBox13:
    break;
  case ECBON_CheckBox14:
    break;
  case ECBON_CheckBox15:
    break;
  case ECBON_CheckBox16:
    break;
  default:

    break;

  }
}

void CClassifyWin::slot_openTrainingSet(bool aClicked)
{
  if (NULL != m_Ui->lineEdit->text())  //打开新的训练集提醒;
  {
    int clickedButton = QMessageBox::warning(this, tr("Prompting"),
                        tr("There has already a \"Training Set\"!\n"
                           "Do you really want to open a new one?"),
                        QMessageBox::Yes, QMessageBox::No); 
                    
    if (clickedButton == QMessageBox::No)
    {
      return;
    } 
  }
  if (savePath(m_Ui->lineEdit))
  {
    m_Ui->pushButton_4->setEnabled(true);
    m_IsTrained = false;
  }
}

void CClassifyWin::slot_openClassifySet(bool aClicked)
{
  if (savePath(m_Ui->lineEdit_2))
  {
    if (m_IsTrained == true)
    {
      m_Ui->pushButton_3->setEnabled(true);
    }
  }
}

void CClassifyWin::slot_beginClassify(bool aClicked)
{
  SDataPack dataPack;
  dataPack.aFilePath = QString2ToStr(m_Ui->lineEdit_2->text());
  dataPack.aFlag = EOF_Classify;
  dataPack.aSrcArray = NULL;
  dataPack.aSrcArraySize = 0;

  m_WorkThread->start();
  m_waitDialog->beginWait();
  emit signal_SendData(dataPack);
 // m_ClassifyFile->operateClassifyFile();
}

void CClassifyWin::slot_beginTraining(bool aClicked)
{ 
  findOutAllCheckedBox();   //记录所有已选分类属性;

  SDataPack dataPack;
  dataPack.aFilePath = QString2ToStr(m_Ui->lineEdit->text());
  dataPack.aFlag = EOF_Training;
  dataPack.aSrcArray = m_AllCheckedBox;
  dataPack.aSrcArraySize = m_CheckedBoxNum;
  
  m_WorkThread->start();
  m_waitDialog->beginWait();
  emit signal_SendData(dataPack);
}

void CClassifyWin::slot_operateFinished(EOperateFlag aFlag)
{
  switch (aFlag)
  {
  case EOF_TrainingFinished:
    m_IsTrained = true;
    m_Ui->pushButton_4->setEnabled(false);
    if (!m_Ui->lineEdit_2->text().isEmpty())
    {
      m_Ui->pushButton_3->setEnabled(true);
    }
    m_WorkThread->quit();
    break;
  case EOF_ClassifyFinished:
    {//分类结束后展示结果;
      char buf[16] = {0};
      sprintf(buf,"result_P%d",CStatisticBayes::getClassifyTimes());
      QString tabName = buf;
      CTabWidget::getInstance()->newTab(new CResultWin(CResultWin::ESRT_Probablity), tabName);

      m_Ui->pushButton_3->setEnabled(false);
      m_WorkThread->quit();
      break;
    }
  case EOF_NULL:
    QMessageBox::warning(this, tr("Prompting"),
                tr("Training Or Classify Failed!!\nPlease Retry!!!"),
                QMessageBox::Ok);
    break;
  default:
    return;
  }
  m_waitDialog->stopWaitDialog();
}

//用于测试某些代码的函数;
void CClassifyWin::test()
{
#if _TEST_FOR_SOME_HEARDER_
  float probablity = CBayesAlgorithm::getInstance()->calcProbablity(1000, 32);



#endif
}