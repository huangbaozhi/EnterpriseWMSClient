# =========================================
# Common.cmake
# Enterprise WMS Client - Global Build Rules
# =========================================

include_guard(GLOBAL)

# -------------------------------------------------
# 基础语言与标准
# -------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------------------------
# 默认构建类型（多配置生成器下不生效）
# -------------------------------------------------
if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# -------------------------------------------------
# 编译器警告等级（企业级）
# -------------------------------------------------
if (MSVC)
    add_compile_options(
        /W4            # 高警告等级
        /permissive-   # 严格 C++
        /Zc:__cplusplus
    )
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# -------------------------------------------------
# Qt 自动工具（WMS UI 必需）
# -------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# -------------------------------------------------
# 平台宏（方便后续跨平台）
# -------------------------------------------------
add_compile_definitions(
    $<$<PLATFORM_ID:Windows>:WMS_PLATFORM_WINDOWS>
    $<$<PLATFORM_ID:Linux>:WMS_PLATFORM_LINUX>
)

# -------------------------------------------------
# 构建类型宏
# -------------------------------------------------
add_compile_definitions(
    $<$<CONFIG:Debug>:WMS_DEBUG>
    $<$<CONFIG:Release>:WMS_RELEASE>
)

# -------------------------------------------------
# 输出目录统一（非常关键）
# -------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

foreach (CONFIG Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER ${CONFIG} CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib)
endforeach()

# -------------------------------------------------
# WMS 项目通用开关（后期非常有用）
# -------------------------------------------------
option(WMS_ENABLE_NETWORK "Enable network features" ON)
option(WMS_ENABLE_DATABASE "Enable database features" ON)
option(WMS_ENABLE_TESTS "Enable unit tests" OFF)

# -------------------------------------------------
# MSVC 专用优化（可选）
# -------------------------------------------------
if (MSVC)
    add_compile_definitions(
        _CRT_SECURE_NO_WARNINGS
    )
endif()

# -------------------------------------------------
# 打印关键信息（调试 CMake 用）
# -------------------------------------------------
message(STATUS "WMS Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "WMS C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "WMS Output Dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
