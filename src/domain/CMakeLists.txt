add_library(domain STATIC
    domain_dummy.cpp
    domain_dummy.h
)

target_include_directories(domain
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(domain
    PUBLIC
        runtime
)
