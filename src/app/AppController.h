#pragma once

#include <QObject>

class AppController : public QObject
{
	Q_OBJECT

public:
	AppController(QObject *parent);
	~AppController();
};
