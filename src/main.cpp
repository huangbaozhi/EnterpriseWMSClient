#include "ui/MainWindow.h"
#include "app/AppController.h"
#include "ui/dialogs/LoginDialog.h"

#if _MSC_VER >= 1600    // MSVC 2010+
#pragma execution_character_set("utf-8")
#endif

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppController controller;

    LoginDialog login(&controller);
    if (login.exec() != QDialog::Accepted) {
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
