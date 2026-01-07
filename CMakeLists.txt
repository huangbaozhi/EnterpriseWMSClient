cmake_minimum_required(VERSION 3.16)

# =========================================================
# Project
# =========================================================
project(EnterpriseWMSClient
    VERSION 0.1
    LANGUAGES CXX
)

# =========================================================
# Global common rules (WMS 专用)
# =========================================================
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Common.cmake)

# =========================================================
# Qt
# =========================================================
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# =========================================================
# Sub-modules
# 依赖顺序非常重要（从底层到上层）
# =========================================================
add_subdirectory(src/runtime)
add_subdirectory(src/domain)
add_subdirectory(src/infrastructure)
add_subdirectory(src/app)
add_subdirectory(src/ui)

# =========================================================
# Main executable
# =========================================================
if (QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_executable(EnterpriseWMSClient
        MANUAL_FINALIZATION
        src/main.cpp
    )
else()
    add_executable(EnterpriseWMSClient
        src/main.cpp
    )
endif()

# =========================================================
# Link libraries
# =========================================================
target_link_libraries(EnterpriseWMSClient
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        ui
        app
        domain
        runtime
        infrastructure
)

# =========================================================
# Include directories
# =========================================================
target_include_directories(EnterpriseWMSClient
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# =========================================================
# Qt finalization (Qt6 only)
# =========================================================
if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(EnterpriseWMSClient)
endif()


# =========================================================
# Tests
# =========================================================
add_subdirectory(tests)

#cmake_minimum_required(VERSION 3.16)
#
#project(EnterpriseWMSClient
#    VERSION 0.1
#    LANGUAGES CXX
#)
#
## ========== 全局配置 ==========
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
## Qt 自动工具
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
## ========== Qt ==========
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
#
## ========== 子模块 ==========
#add_subdirectory(src/runtime)
#add_subdirectory(src/domain)
#add_subdirectory(src/infrastructure)
#add_subdirectory(src/app)
#add_subdirectory(src/ui)
#
## ========== 主程序 ==========
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(EnterpriseWMSClient
#        MANUAL_FINALIZATION
#        src/main.cpp
#    )
#else()
#    add_executable(EnterpriseWMSClient
#        src/main.cpp
#    )
#endif()
#
#target_link_libraries(EnterpriseWMSClient
#    PRIVATE
#        Qt${QT_VERSION_MAJOR}::Widgets
#        ui
#        app
#        domain
#        runtime
#        infrastructure
#)
#
#target_include_directories(EnterpriseWMSClient
#    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
#)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(EnterpriseWMSClient)
#endif()



#cmake_minimum_required(VERSION 3.16)
#
#project(EnterpriseWMSClient VERSION 0.1 LANGUAGES CXX)
#
## ========= 基础配置 =========
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
## ========= Qt =========
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
#
## ========= 源码 =========
#set(UI_SOURCES
#    ui/MainWindow.cpp
#    ui/MainWindow.h
#
#    ui/pages/DashboardWidget.cpp
#    ui/pages/DashboardWidget.h
#
#    ui/pages/InboundWidget.cpp
#    ui/pages/InboundWidget.h
#
#    ui/pages/CreateInboundWidget.cpp
#    ui/pages/CreateInboundWidget.h
#
#    ui/pages/InboundListWidget.cpp
#    ui/pages/InboundListWidget.h
#)
#
#set(APP_SOURCES
#    app/AppController.cpp
#    app/AppController.h
#)
#
#set(MAIN_SOURCES
#    main.cpp
#)
#
## ========= 可执行程序 =========
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(EnterpriseWMSClient
#        MANUAL_FINALIZATION
#        ${MAIN_SOURCES}
#        ${UI_SOURCES}
#        ${APP_SOURCES}
#    )
#else()
#    add_executable(EnterpriseWMSClient
#        ${MAIN_SOURCES}
#        ${UI_SOURCES}
#        ${APP_SOURCES}
#    )
#endif()
#
## ========= include =========
#target_include_directories(EnterpriseWMSClient
#    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}
#)
#
## ========= link =========
#target_link_libraries(EnterpriseWMSClient
#    PRIVATE
#        Qt${QT_VERSION_MAJOR}::Widgets
#)
#
## ========= bundle =========
#set_target_properties(EnterpriseWMSClient PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING
#        ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(EnterpriseWMSClient)
#endif()



##cmake_minimum_required(VERSION 3.5)
#cmake_minimum_required(VERSION 3.16)
#
#project(EnterpriseWMSClient VERSION 0.1 LANGUAGES CXX)
#
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
#
#set(PROJECT_SOURCES
#        main.cpp
#        ui/MainWindow.cpp
#        ui/MainWindow.h
#
#        ui/pages/DashboardWidget.cpp
#        ui/pages/DashboardWidget.h
#
#        ui/pages/InboundWidget.cpp
#        ui/pages/InboundWidget.h
#
#        ui/pages/CreateInboundWidget.cpp
#        ui/pages/CreateInboundWidget.h
#
#        ui/pages/InboundListWidget.cpp
#        ui/pages/InboundListWidget.h
#)
#
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(EnterpriseWMSClient
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
## Define target properties for Android with Qt 6 as:
##    set_property(TARGET EnterpriseWMSClient APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
##                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
## For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(EnterpriseWMSClient SHARED
#            ${PROJECT_SOURCES}
#        )
## Define properties for Android with Qt 5 after find_package() calls as:
##    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(EnterpriseWMSClient
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()
#
#target_link_libraries(EnterpriseWMSClient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#
#set_target_properties(EnterpriseWMSClient PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(EnterpriseWMSClient)
#endif()
