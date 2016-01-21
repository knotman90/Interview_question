cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)
include(configure.cmake)



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


link_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SRC
    "include/*.h"
    "source/*.cpp"
)



add_library(DSL ${SHAREDORSTATIC} ${SRC})
set_target_properties(DSL PROPERTIES VERSION "${DSL_VERSION}" SOVERSION "${DSL_MAJOR_VERSION}")
target_compile_features(DSL PRIVATE cxx_deleted_functions)

if(${BUILD_TESTS} STREQUAL "ON")
        add_subdirectory(tests)
        #install(DIRECTORY examples DESTINATION ${INSTALL_EXAMPLE_DIR}/OpenCAL)
endif()

