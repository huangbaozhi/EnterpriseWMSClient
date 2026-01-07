add_executable(test_domain
    test_domain.cpp
)

target_link_libraries(test_domain
    PRIVATE
        domain
)

target_include_directories(test_domain
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_test(
    NAME domain_test
    COMMAND test_domain
)
