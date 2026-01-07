add_executable(test_runtime
    test_runtime.cpp
)

target_link_libraries(test_runtime
    PRIVATE
        runtime
)

target_include_directories(test_runtime
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_test(
    NAME runtime_test
    COMMAND test_runtime
)
