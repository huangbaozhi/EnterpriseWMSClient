#include "AppController.h"

#include <QMetaObject>
#include <QThread>
#include <chrono>
#include <thread>

AppController::AppController(QObject *parent)
	: QObject(parent)
{
}

AppController::~AppController()
{
}


void AppController::loginAsync(const QString& username,
    const QString& password,
    int timeoutMs) {
    // 使用 std::thread / 线程池（这里先用 thread，方便理解）
    std::thread([=]() {
        simulateLogin(username, password, timeoutMs);
        }).detach();
}

void AppController::simulateLogin(const QString& user,
    const QString& pwd,
    int timeoutMs) {
    // ===== 模拟网络延迟 =====
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    LoginResult result;

    // ===== 模拟超时 =====
    if (timeoutMs < 1500) {
        result.status = LoginStatus::Timeout;
        result.message = "登录超时，请检查网络";
    }
    // ===== 模拟成功 / 失败 =====
    else if (user == "admin" && pwd == "123456") {
        result.status = LoginStatus::Success;
        result.message = "登录成功";
    }
    else {
        result.status = LoginStatus::Failed;
        result.message = "用户名或密码错误";
    }

    // ===== 回到 Qt 主线程发信号 =====
    QMetaObject::invokeMethod(this, [=]() {
        emit loginFinished(result);
        }, Qt::QueuedConnection);
}