#include "ui/MainWindow.h"

#if _MSC_VER >= 1600    // MSVC 2010+
#pragma execution_character_set("utf-8")
#endif

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
