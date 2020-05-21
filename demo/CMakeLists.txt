set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(lexical)

set (src main.cc)
set(hdr)

RE2C(src scanner.re)

FOREACH(f ${src})
  set_source_files_properties(${f} PROPERTIES LANGUAGE CXX )
ENDFOREACH()

LEMON(src hdr parser.yy)


# 

add_executable(demo main.cc ${src} ${hdr})
target_include_directories(demo
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
        )



