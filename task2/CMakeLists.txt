cmake_minimum_required(VERSION 3.10)
project(Kitten)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_subdirectory(${PROJECT_SOURCE_DIR}/B)
target_link_libraries(C Cat)

add_custom_command(
OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
COMMAND python3 preparing.py
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A
)

add_custom_target(My DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)
add_dependencies(C My)

target_include_directories(C PRIVATE ${PROJECT_SOURCE_DIR})

find_package(GTest REQUIRED)

add_executable(CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp ${PROJECT_SOURCE_DIR}/C/sometests.cpp)
add_dependencies(CTest My)
target_include_directories(CTest PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread)
