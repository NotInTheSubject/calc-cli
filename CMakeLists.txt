cmake_minimum_required(VERSION 3.13)
project(calc-cli VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
