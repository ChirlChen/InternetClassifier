#include "WaitDialog.h"
#include "debug_new.h"

CWaitDialog::CWaitDialog(QWidget *parent)
    : QDialog(parent)
{
  setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体;
  this->setFixedSize(200, 100);
  this->setWindowOpacity(0.8);
  this->setStyleSheet("background-color: rgb(55, 135, 215);");
  this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

  m_label = new QLabel(this);
  m_label->setStyleSheet("background-color: transparent");
  m_label->setFixedSize(200, 100);
  m_tipLabel = new QLabel(this);
  m_tipLabel->setStyleSheet("background-color: rgb(255, 255, 255);");
  m_tipLabel->setText("Please Wait!!");
  m_tipLabel->setGeometry(60, 85, 80, 15);
  m_movie = new QMovie(":/new/prefix1/Resources/wait.gif");
  m_label->setMovie(m_movie);
  m_label->setScaledContents(true);
  m_movie->start();

  this->hide();
}

CWaitDialog::~CWaitDialog()
{
  m_movie->stop();
  delete m_movie;
  delete m_label;
}

void CWaitDialog::stopWaitDialog()
{
  m_movie->stop();
  this->hide();
}

void CWaitDialog::beginWait()
{
  m_movie->start();
  this->show();
}