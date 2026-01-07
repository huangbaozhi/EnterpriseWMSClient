#include "InboundWidget.h"

#include <QTabWidget>
#include <QVBoxLayout>

/**
* @description: 入库管理界面
* @brief: InboundWidget.cpp
*/

InboundWidget::InboundWidget(QWidget *parent)
	: QWidget(parent)
{

	auto* tabs = new QTabWidget;
	//tabs->addTab(new CreateInboundWidget, "新建入库单");
	//tabs->addTab(new InboundListWidget, "入库单列表");

	auto* layout = new QVBoxLayout(this);
	layout->addWidget(tabs);
}

InboundWidget::~InboundWidget()
{
}
