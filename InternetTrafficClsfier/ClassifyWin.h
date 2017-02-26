#ifndef CLASSIFYWIN_H
#define CLASSIFYWIN_H

#include "FileOperator.h"
#include "DataStructDef.h"
#include <QWidget>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLineEdit>
#include <QMovie>
#include <QLabel>
        
class Ui_CClassifyWin;
class CWaitDialog;
class CClassifyWin : public QWidget
{
    Q_OBJECT

public:
    explicit CClassifyWin(QWidget *parent = 0);
    ~CClassifyWin();

    bool showPathInLineEdit(QLineEdit *aLineEdit, const char *aPath);

public slots:
    void slot_clickedCheckBox() const;

    void slot_openTrainingSet(bool);
    void slot_openClassifySet(bool);
    void slot_beginClassify(bool);
    void slot_beginTraining(bool);
    void slot_operateFinished(EOperateFlag aFlag);

private:
    void findOutAllCheckedBox();     //找出所有的被勾选的CheckBox，并记录它们的属性号;
    bool recordChoosedCheckBox(/*const */QCheckBox *checkBox, int &idx);  //检测指定CheckBox是否被勾选,被钩选则记录到数组中;
    void addAllCheckBox2Group() const;  //把所有的属性CheckBox加入到ButtonGroup中，方便对点击事件进行操作;
    bool savePath(QLineEdit *aLineEdit);
   
    char *QString2ToStr(QString &aQStr) ;

    void test(); //用于测试某些代码
signals:
    void signal_SendData(SDataPack aDataPack);   //发送数据包的信号;
private:
    Ui_CClassifyWin *m_Ui;
    QButtonGroup *m_CheckBoxGroup;
    
    DEFSETGET(AllCheckedBox, unsigned short *, private); //勾选的checkbox的序号;
    DEFSETGET(CheckedBoxNum, unsigned short, private);   //所有的勾选的checkBox数量;
    DEFSETGET(FileOperator, CFileOperator *, private);
    
    bool m_IsTrained; //标志是否已经训练过了;
    char *m_destPath;   //临时保存需要传递的路径;
    QThread *m_WorkThread;    //数据处理线程;
    CWaitDialog *m_waitDialog;  //等待提示窗;
};

#endif // CLASSIFYWIN_H
