#include "MainWindow.h"
#include <QtWidgets/QApplication>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    QApplication a(argc, argv);
    CMainWindow w;
    w.show();
    return a.exec();
}
