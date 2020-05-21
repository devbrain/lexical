#ifndef CALC_SCANNER_DEF_H
#define CALC_SCANNER_DEF_H

#include <assert.h>

typedef union {
    int int_value;
} YYSTYPE;

typedef struct ParserState_ {
    int result;
} ParserState;

#endif // CALC_SCANNER_DEF_H_
