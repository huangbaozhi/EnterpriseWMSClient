add_library(infrastructure STATIC
    infra_dummy.cpp
    infra_dummy.h
)

target_include_directories(infrastructure
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        #${PROJECT_SOURCE_DIR}/src
)
