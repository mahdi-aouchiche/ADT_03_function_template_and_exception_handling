cmake_minimum_required(VERSION 3.0.0)
project(CS014_Lab3 VERSION 1.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_executable(template_example 
    src/main.cpp
)

add_executable(template_test
    src/unit_test.cpp
)

TARGET_LINK_LIBRARIES(template_test gtest)
TARGET_COMPILE_DEFINITIONS(template_test PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

