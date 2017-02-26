#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>

class CClassifyWin;
class Ui_CMainWindow;
class CTabWidget;

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
private:  //禁止拷贝和赋值;
    CMainWindow(const CMainWindow &){}
    CMainWindow &operator=(const CMainWindow &){}

public:
    void initLocalVar();  //初始化成员变量,必须在InitConnect()之前调用;
    void initConnect() const;  //初始化信号和槽的链接;
    
    void initStatusBar();

public slots:
    void slot_clickClsBegin();
    void slot_clickRltShowProbablity();
    void slot_clickRltShowNum();
    void slot_exit();
private:
    Ui_CMainWindow *m_ui;
};

#endif // MAINWINDOW_H
