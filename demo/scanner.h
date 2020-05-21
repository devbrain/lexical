#ifndef CALC_SCANNER_H
#define CALC_SCANNER_H

#include "scanner.def.h"


#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

class Scanner {
private:
    std::istream *ifs;
 
    // buffer memory
    char* m_buffer;
    // current position
    char* m_cursor;
    char* m_limit;
    char* m_token;
    char* m_marker;
    int m_buffer_size;
    int m_lineno;
 
public:
    Scanner( std::istream *ifs_, int init_size=1024 );
    ~Scanner();
    
    void increment_line_number();
    bool fill(int n);
    std::string text();
    int length();
    int lineno();
    int scan(YYSTYPE& yylval);

};

#endif
