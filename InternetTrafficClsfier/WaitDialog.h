#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include <QLabel>
#include <QMovie>
#include <QDialog>

class CWaitDialog : public QDialog
{
    Q_OBJECT

public:
    CWaitDialog(QWidget *parent = 0);
    ~CWaitDialog();

    void beginWait();
    void stopWaitDialog();
private:
    QMovie *m_movie;
    QLabel *m_label;
    QLabel *m_tipLabel;
};

#endif // WAITDIALOG_H
