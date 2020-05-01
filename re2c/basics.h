/* $Id$ */
#ifndef _basics_h
#define _basics_h

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 6)
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wpedantic"
#if (__GNUC__ == 4 && __GNUC_MINOR__ > 9)
#pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif
#pragma GCC diagnostic ignored "-Wreturn-type"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wundef"
#pragma GCC diagnostic ignored "-Wconversion"
#if __GNUC__ >= 6
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#endif
#endif // > gcc 4.6

#if !defined(_WIN32)
#include "config.h"
#else
#include "config_w32.h"
#endif

namespace re2c
{

#if SIZEOF_CHAR == 1
typedef unsigned char byte;
#elif SIZEOF_SHORT == 1
typedef unsigned short byte;
#elif SIZEOF_INT == 1
typedef unsigned int byte;
#elif SIZEOF_LONG == 1
typedef unsigned long byte;
#else
typedef unsigned char byte;
#endif

#if SIZEOF_CHAR == 2
typedef unsigned char word;
#elif SIZEOF_SHORT == 2
typedef unsigned short word;
#elif SIZEOF_INT == 2
typedef unsigned int word;
#elif SIZEOF_LONG == 2
typedef unsigned long word;
#else
typedef unsigned short word;
#endif

#if SIZEOF_CHAR == 4
typedef unsigned char dword;
#elif SIZEOF_SHORT == 4
typedef unsigned short dword;
#elif SIZEOF_INT == 4
typedef unsigned int dword;
#elif SIZEOF_LONG == 4
typedef unsigned long dword;
#else
typedef unsigned long dword;
#endif

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

} // end namespace re2c

#endif
