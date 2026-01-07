#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QListWidget;
class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUi();
    void setupHeader();
    void setupSidebar();
    void setupCentral();
    void setupRightSidebar();
    void setupStatusBar();

private:
    QListWidget* navList_;
    QStackedWidget* stack_;

};
#endif // MAINWINDOW_H
