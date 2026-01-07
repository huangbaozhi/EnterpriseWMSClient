add_library(ui STATIC
    MainWindow.cpp
    MainWindow.h

    pages/DashboardWidget.cpp
    pages/DashboardWidget.h

    pages/InboundWidget.cpp
    pages/InboundWidget.h

    pages/CreateInboundWidget.cpp
    pages/CreateInboundWidget.h

    pages/InboundListWidget.cpp
    pages/InboundListWidget.h
)

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ui
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        app
)
