cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)

include(configure.cmake)


project(DSL VERSION ${OPENCAL_VERSION} LANGUAGES  CXX)


if ( ENABLE_SHARED )
        set( SHAREDORSTATIC SHARED )
else()
        set( SHAREDORSTATIC STATIC )
endif()

add_definitions( -DPACKAGE="OPENCAL" -DVERSION="${OPENCAL_VERSION}" )


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/*)


file(GLOB SRC_MEMORY
    "include/memory/*.h"
    "source/memory/*.cpp"
)

file(GLOB SRC_LIST
    "include/list/*.h"
    "source/list/*.cpp"
)

file(GLOB SRC_COMMON
    "include/common/*.h"
    "source/common/*.cpp"
)

file(GLOB SRC_ALGORITHM
    "include/algorithm/*.h"
    "source/algorithm/*.cpp"
)

file(GLOB SRC_VECTOR
    "include/vector/*.h"
    "source/vector/*.cpp"
)





add_library(DSL ${SHAREDORSTATIC} ${SRC_MEMORY} ${COMMON_SRC} ${SRC_LIST} ${SRC_ALGORITHM} ${SRC_VECTOR})
set_target_properties(DSL PROPERTIES VERSION "${DSL_VERSION}" SOVERSION "${DSL_MAJOR_VERSION}" LINKER_LANGUAGE CXX)
set_property(TARGET DSL PROPERTY CXX_STANDARD 14)

target_compile_features(DSL PRIVATE cxx_deleted_functions)

if(${BUILD_TESTS} STREQUAL "ON")
       add_subdirectory(tests)
        #install(DIRECTORY examples DESTINATION ${INSTALL_EXAMPLE_DIR}/OpenCAL)
endif()
