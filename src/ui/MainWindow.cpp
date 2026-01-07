#pragma execution_character_set("utf-8")

#include "MainWindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

#include "pages/DashboardWidget.h"
#include "pages/InboundWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
}

MainWindow::~MainWindow()
{
}


void MainWindow::setupUi() {
    //resize(1400, 900);
	this->setFixedSize(1400, 900);
    setupHeader();
    setupSidebar();
    setupCentral();
    setupRightSidebar();
    setupStatusBar();
}

void MainWindow::setupHeader() {
    auto* toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    toolbar->setFixedHeight(50);

    auto* title = new QLabel("WMS 仓储管理系统");
    title->setStyleSheet("font-weight:600;font-size:16px;");

    auto* userInfo = new QLabel("张三（管理员）");

    toolbar->addWidget(title);
    toolbar->addSeparator();
    toolbar->addWidget(userInfo);

    addToolBar(Qt::TopToolBarArea, toolbar);
}

void MainWindow::setupSidebar() {
    navList_ = new QListWidget;
    navList_->setFixedWidth(200);

    navList_->addItem("系统概览");
    navList_->addItem("入库管理");
    navList_->addItem("出库管理");
    navList_->addItem("库存管理");
    navList_->addItem("任务中心");
    navList_->addItem("日志中心");
    navList_->addItem("系统设置");

    navList_->setCurrentRow(0);
}

void MainWindow::setupCentral() {
    stack_ = new QStackedWidget;

    stack_->addWidget(new DashboardWidget);
    stack_->addWidget(new InboundWidget);
    //stack_->addWidget(new OutboundWidget);
    //stack_->addWidget(new InventoryWidget);
    //stack_->addWidget(new TaskWidget);
    //stack_->addWidget(new LogWidget);
    //stack_->addWidget(new SettingsWidget);

    connect(navList_, &QListWidget::currentRowChanged,
        stack_, &QStackedWidget::setCurrentIndex);

    auto* central = new QWidget;
    auto* layout = new QHBoxLayout(central);
    layout->setMargin(0);
    layout->addWidget(navList_);
    layout->addWidget(stack_);

    setCentralWidget(central);
}

void MainWindow::setupRightSidebar() {
    auto* dock = new QDockWidget("快捷操作", this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);

    auto* widget = new QWidget;
    auto* layout = new QVBoxLayout(widget);

    layout->addWidget(new QPushButton("扫码入库"));
    layout->addWidget(new QPushButton("新建出库单"));
    layout->addWidget(new QPushButton("库存盘点"));
    layout->addStretch();

    dock->setWidget(widget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::setupStatusBar() {
    auto* status = new QStatusBar;
    status->showMessage("系统运行正常 | 服务已连接");
    setStatusBar(status);
}

