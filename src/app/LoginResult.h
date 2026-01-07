#pragma once
#include <QString>

enum class LoginStatus {
    Success,
    Failed,
    Timeout
};

struct LoginResult {
    LoginStatus status;
    QString message;
};