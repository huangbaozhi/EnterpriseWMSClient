#pragma execution_character_set("utf-8")
#include "DashboardWidget.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>

/**
* @description: 系统概览界面
* @brief: DashboardWidget.cpp
*/

DashboardWidget::DashboardWidget(QWidget *parent)
	: QWidget(parent)
{
	auto* layout = new QGridLayout(this);

	auto createCard = [](const QString& title, const QString& value) {
		auto* box = new QGroupBox(title);
		auto* v = new QVBoxLayout(box);
		v->addWidget(new QLabel(value));
		return box;
		};

	layout->addWidget(createCard("今日入库", "245"), 0, 0);
	layout->addWidget(createCard("今日出库", "189"), 0, 1);
	layout->addWidget(createCard("库存总量", "58420"), 0, 2);
	layout->addWidget(createCard("库存预警", "15"), 0, 3);
}

DashboardWidget::~DashboardWidget()
{
}
