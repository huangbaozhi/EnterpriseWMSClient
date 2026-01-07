#pragma once

#include <QDialog>
#include "app/AppController.h"

class QLineEdit;
class QPushButton;
class QCheckBox;
class QLabel;
class AppController;

class LoginDialog : public QDialog {
    Q_OBJECT
public:
    explicit LoginDialog(AppController* controller, QWidget* parent = nullptr);


private slots:
    void onLoginClicked();
    void onLoginResult(const LoginResult& result);

private:
    AppController* controller_;

    QLineEdit* usernameEdit_;
    QLineEdit* passwordEdit_;
    QPushButton* loginButton_;
    QLabel* statusLabel_;
};
