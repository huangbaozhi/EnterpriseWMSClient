add_library(app STATIC
    AppController.cpp
    AppController.h
    LoginResult.h
)

target_include_directories(app
    PUBLIC
        #${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(app
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        domain
        runtime
        infrastructure
)

