cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)

project(InterviewQuestion LANGUAGES  CXX)

include(configure.cmake)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


include_directories(${CMAKE_SOURCE_DIR}/src/LinkedList)
include_directories(${CMAKE_SOURCE_DIR}/DSL/include/)

file(GLOB SRC_LINKED_LIST
    "src/LinkedList/*.h"
    "src/LinkedList/*.cpp"
)

file(GLOB SRC_TOP_LEVEL
    "src/*.h"
    "src/*.cpp"
)

add_subdirectory(DSL)

add_executable(InterviewQuestion ${SRC_TOP_LEVEL} ${SRC_LINKED_LIST})
target_link_libraries(InterviewQuestion DSL ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
SET_TARGET_PROPERTIES(InterviewQuestion PROPERTIES LINKER_LANGUAGE CXX)
set_property(TARGET InterviewQuestion PROPERTY CXX_STANDARD 14)
