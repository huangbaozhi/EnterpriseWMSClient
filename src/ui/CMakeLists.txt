add_library(ui STATIC
    MainWindow.cpp
    MainWindow.h

    dialogs/LoginDialog.cpp
    dialogs/LoginDialog.h

    pages/DashboardWidget.cpp
    pages/DashboardWidget.h

    pages/InboundWidget.cpp
    pages/InboundWidget.h

    pages/CreateInboundWidget.cpp
    pages/CreateInboundWidget.h

    pages/InboundListWidget.cpp
    pages/InboundListWidget.h

 "widgets/StatCardWidget.h" "widgets/StatCardWidget.cpp")

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        #${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(ui
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        app
)
