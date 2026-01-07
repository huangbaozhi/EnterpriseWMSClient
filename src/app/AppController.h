#pragma once

#include <QObject>
#include <QString>
#include "LoginResult.h"

class AppController : public QObject
{
	Q_OBJECT

public:
    explicit AppController(QObject* parent = nullptr);
	~AppController();

    void loginAsync(const QString& username,
        const QString& password,
        int timeoutMs = 3000);

signals:
    void loginFinished(const LoginResult& result);

private:
    void simulateLogin(const QString& user,
        const QString& pwd,
        int timeoutMs);
};
