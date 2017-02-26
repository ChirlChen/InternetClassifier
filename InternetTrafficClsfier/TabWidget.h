#ifndef _TABWIDGET_H_
#define _TABWIDGET_H_

#include <QTabWidget>
#include <QTabBar>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>

class CTabWidget : public QTabWidget
{
  Q_OBJECT

public:
  explicit CTabWidget(QWidget *parent = 0);
  ~CTabWidget(void);

public:
  bool newTab(QWidget *a_targetWin, const QString &a_tabName);//在标签窗口中添加新标签;
  
  template<class WidgetType> //类体内的函数模板,似乎只能在类体内实现;
  int ifWidgetExist(WidgetType *aTargetType) const
  {
    int cnt = count();

    for (int idx = 0; idx < cnt; ++ idx)
    {
      if (NULL != dynamic_cast<WidgetType *> (widget(idx)))
      {
        return idx;
      }
    }
    return -1;
  }
  bool ifWidgetExist(const QString &aTabName) const;

  static CTabWidget *getInstance();
  static void destroyInstance();
public slots:
  void slot_NewTab();
  void slot_CloseTab(int idx);
  void slot_ShowTab(QAction *a);

protected:
  void resizeEvent(QResizeEvent *e);

private:
  enum EResetFlag{ERF_New, ERF_Close, ERF_Normal, ERF_Special,};
  
  void initTabControl();
  void resetTabBar(EResetFlag flag) const;
  void setListTabs() const;

private:
 
  QToolBar *m_tabControl;
  QAction *m_newTab;
  QAction *m_listTab;
  QWidget *m_paddingWidget;

private:
  static CTabWidget *m_SingleTon;
};

#endif