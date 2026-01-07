add_library(runtime STATIC
    runtime_dummy.cpp
    runtime_dummy.h
)

target_include_directories(runtime
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(runtime PUBLIC cxx_std_17)

#target_include_directories(runtime
#    PUBLIC
#        ${PROJECT_SOURCE_DIR}/src
#)
#
#target_compile_features(runtime PUBLIC cxx_std_17)