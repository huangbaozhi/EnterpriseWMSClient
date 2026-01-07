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
        #${PROJECT_SOURCE_DIR}/src
)

target_include_directories(ui
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
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
