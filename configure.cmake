set(DSL_MAJOR_VERSION 1)
set(DSL_MINOR_VERSION 0)
set(DSL_PATCH_VERSION 0)
set(DSL_VERSION
  ${DSL_MAJOR_VERSION}.${DSL_MINOR_VERSION}.${DSL_PATCH_VERSION})

option(BUILD_DOCUMENTATION  "Build the HTML based API documentation (Doxygen required)"             OFF)

option(BUILD_TESTS  "Test suites for the libraries"  ON)

option(ENABLE_SHARED "Enable Shared Libraries" OFF)


