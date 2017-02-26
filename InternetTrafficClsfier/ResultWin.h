#ifndef RESULTWIN_H
#define RESULTWIN_H

#include <QWidget>
#include "ui_ResultWin.h"

class CResultWin : public QWidget
{
    Q_OBJECT
public:
  enum EShowResultType //控制显示哪种类型的结果;
  {
    ESRT_Probablity,  //概率型;
    ESRT_Number,      //数值型;
  };
public:
    CResultWin(EShowResultType aType = ESRT_Probablity, QWidget *parent = 0);
    ~CResultWin();

    void showClassifyResult(EShowResultType aType);
    void showProbablity(int &aColumn, int &aRow);
    void showNumber(int &aColumn, int &aRow);

private:
    Ui::CResultWin ui;
};

#endif // RESULTWIN_H
