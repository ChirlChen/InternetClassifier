#include "TabWidget.h"
#include "MacroDef.h"
#include "debug_new.h"

CTabWidget::CTabWidget(QWidget *parent /*= 0*/)
  : m_tabControl(NULL),
    m_newTab(NULL),
    m_listTab(NULL),
    m_paddingWidget(NULL)
{
  this->setUsesScrollButtons(true);
  this->setTabsClosable(true);
  this->setMovable(true);

  initTabControl();
  this->setCornerWidget(m_tabControl);
  resetTabBar(ERF_Normal);

  connect(this, SIGNAL(tabCloseRequested(int)),
          this, SLOT(slot_CloseTab(int)));
}

CTabWidget::~CTabWidget(void)
{
 
}

void CTabWidget::resizeEvent(QResizeEvent *e)
{
  resetTabBar(ERF_Normal);
  QTabWidget::resizeEvent(e);
}

void CTabWidget::resetTabBar(EResetFlag flag) const
{
  QSize size = this->size();
  int tabsWidth = 0;
  int tabsHeight = tabBar()->height();
  int tabs = count();
  if (ERF_New == flag || ERF_Normal == flag)
  {
    for (int idx = 0; idx < tabs; ++idx)
    {
      tabsWidth += tabBar()->tabRect(idx).width();
    }  
  }
  else
  {
    for (int idx = 0; idx < tabs - 1; ++idx)
    {
      tabsWidth += tabBar()->tabRect(idx).width();
    }
  }

  if (size.width() > tabsWidth)
  {
    if (ERF_Special == flag)
    {
      int minWidth = Max(0, size.width() - tabsWidth - 40);
      m_paddingWidget->setMinimumWidth(minWidth);
    }
    else
    {
      int minWidth = Max(0, size.width() - tabsWidth - 35);
      m_paddingWidget->setMinimumWidth(minWidth);
    }
    m_listTab->setVisible(false);
  }
  else
  {
    m_listTab->setVisible(true);
    this->setListTabs();

    m_paddingWidget->setMinimumWidth(0);
  }

  m_paddingWidget->setMinimumHeight(tabsHeight);
}

void CTabWidget::initTabControl()
{
  m_tabControl = new QToolBar(this);
  QList<QAction *> qlistActions;
//  m_newTab = new QAction("+", tab_control);
  m_listTab = new QAction("v", m_tabControl);
  m_listTab->setVisible(false);
//  qlistActions << m_newTab;
  qlistActions << m_listTab;
  m_tabControl->addActions(qlistActions);

  m_paddingWidget = new QWidget(this);
  m_tabControl->addWidget(m_paddingWidget);
  m_tabControl->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);

  //connect(m_newTab, SIGNAL(triggered()),
  //        this, SLOT(slot_NewTab()));
}

bool CTabWidget::newTab(QWidget *aTagetWin, const QString &aTabName)
{
  this->addTab(aTagetWin, aTabName);
  if (!tabsClosable())
  {
    setTabsClosable(true);
  }
  setCurrentWidget(aTagetWin);
  resetTabBar(ERF_New);
  
  return true;
}

void CTabWidget::slot_NewTab()
{
  this->addTab(new QWidget, "newWidget");
  if (!tabsClosable())
  {
    setTabsClosable(true);
  }

  resetTabBar(ERF_New);
}

void CTabWidget::slot_CloseTab(int idx)
{
  widget(idx)->deleteLater();
  resetTabBar(ERF_Close);
}

void CTabWidget::setListTabs() const
{
  QMenu *list = new QMenu();
  int cnt = count();
  for (int idx = 0; idx < cnt; ++idx)
  {
    QAction *action = new QAction(tabText(idx), list);
    action->setProperty("index", idx);
    list->addAction(action);
  }

  QMenu *old = m_listTab->menu();
  delete old;
  m_listTab->setMenu(list);
  connect(list, SIGNAL(triggered(QAction *)),
          this, SLOT(slot_ShowTab(QAction *)));
}

void CTabWidget::slot_ShowTab(QAction *a)
{
  int idx = a->property("index").toInt();
  setCurrentIndex(idx);
}

bool CTabWidget::ifWidgetExist(const QString &aTabName) const
{
  if (0 == aTabName.size())
  { return false;}
  int cnt = count();

  for (int idx = 0; idx < cnt; ++ idx)
  {
    if (aTabName == this->tabText(idx))
    {
      return true;
    }
  }
  return false;
}

CTabWidget *CTabWidget::m_SingleTon = NULL;

CTabWidget *CTabWidget::getInstance()
{
  if (NULL == m_SingleTon)
  {
    m_SingleTon = new CTabWidget;
  }
  return m_SingleTon;
}

void CTabWidget::destroyInstance()
{
  if (NULL != m_SingleTon)
  {
    delete m_SingleTon;
    m_SingleTon = NULL;
  }
}



