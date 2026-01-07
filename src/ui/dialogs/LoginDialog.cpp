#pragma execution_character_set("utf-8")
#include "LoginDialog.h"
#include "app/AppController.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

LoginDialog::LoginDialog(AppController* controller, QWidget* parent)
    : QDialog(parent),
    controller_(controller) {

    setWindowTitle("WMS µÇÂ¼");
    setFixedSize(360, 260);
    setModal(true);

    auto* layout = new QVBoxLayout(this);

    usernameEdit_ = new QLineEdit;
    usernameEdit_->setPlaceholderText("ÓÃ»§Ãû");

    passwordEdit_ = new QLineEdit;
    passwordEdit_->setPlaceholderText("ÃÜÂë");
    passwordEdit_->setEchoMode(QLineEdit::Password);

    loginButton_ = new QPushButton("µÇÂ¼");
    loginButton_->setDefault(true);

    statusLabel_ = new QLabel;
    statusLabel_->setStyleSheet("color: red;");

    layout->addWidget(usernameEdit_);
    layout->addWidget(passwordEdit_);
    layout->addWidget(loginButton_);
    layout->addWidget(statusLabel_);

    connect(loginButton_, &QPushButton::clicked,
        this, &LoginDialog::onLoginClicked);

    connect(controller_, &AppController::loginFinished,
        this, &LoginDialog::onLoginResult);
}

void LoginDialog::onLoginClicked() {
    statusLabel_->setText("ÕýÔÚµÇÂ¼...");
    loginButton_->setEnabled(false);

    controller_->loginAsync(
        usernameEdit_->text(),
        passwordEdit_->text(),
        3000
    );
}

void LoginDialog::onLoginResult(const LoginResult& result) {
    loginButton_->setEnabled(true);

    switch (result.status) {
    case LoginStatus::Success:
        accept();
        break;
    case LoginStatus::Failed:
    case LoginStatus::Timeout:
        statusLabel_->setText(result.message);
        break;
    }
}

