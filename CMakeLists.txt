cmake_minimum_required (VERSION 3.11)

project(lexical VERSION 0.0.1 LANGUAGES CXX C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(BINARY_OUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(LIB_OUT_DIR ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUT_DIR})


add_subdirectory(re2c)
add_subdirectory(lemon)
add_subdirectory(demo)

install (TARGETS lemon re2c
  EXPORT lexical-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )

install(
    FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/lemon/lempar.c
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)


set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/lexical)

install(EXPORT lexical-targets
    FILE lexical-targets.cmake
    NAMESPACE lexical::
    DESTINATION ${INSTALL_CONFIGDIR})

write_basic_package_version_file(
    ${CMAKE_BINARY_DIR}/cmake/lexical-config-version.cmake
    VERSION ${VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/lexical-config.cmake.in
    ${CMAKE_BINARY_DIR}/cmake/lexical-config.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(
    FILES
    ${CMAKE_BINARY_DIR}/cmake/lexical-config.cmake
    ${CMAKE_SOURCE_DIR}/cmake/lexical.cmake
    ${CMAKE_BINARY_DIR}/cmake/lexical-config-version.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)


export(EXPORT lexical-targets
    FILE ${CMAKE_BINARY_DIR}/cmake/lexical-targets.cmake
    NAMESPACE lexical::
    )
  
export(PACKAGE lexical)

