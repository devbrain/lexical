set (src lemon.c)
add_executable (lemon ${src})
add_executable(lexical::lemon ALIAS lemon)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lempar.c ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lempar.c COPYONLY)
