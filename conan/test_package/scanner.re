#include "scanner.h"
#include "parser.h"


void Scanner::increment_line_number() {
    m_lineno++;
}

Scanner::Scanner( std::istream *ifs_, int init_size)
    : m_buffer(0)
    , m_cursor(0)
    , m_limit(0)
    , m_token(0)
    , m_marker(0)
    , m_buffer_size(init_size)
    , m_lineno(1)
{
    m_buffer = new char[m_buffer_size];
    m_cursor = m_limit = m_token = m_marker = m_buffer;
    ifs = ifs_;
}
 
Scanner::~Scanner() {
    delete [] m_buffer;
}
 
bool Scanner::fill(int n) {
 
    // is eof?
    if (ifs->eof()) {
	if ((m_limit-m_cursor) <= 0) {
	    return false;
	}
    }
 
    int restSize = m_limit-m_token;
    if (restSize+n >= m_buffer_size) {
	// extend buffer
	m_buffer_size *= 2;
	char* newBuffer = new char[m_buffer_size];
	for (int i=0; i<restSize; ++i) { // memcpy
	    *(newBuffer+i) = *(m_token+i);
	}
	m_cursor = newBuffer + (m_cursor-m_token);
	m_token = newBuffer;
	m_limit = newBuffer + restSize;
 
	delete [] m_buffer;
	m_buffer = newBuffer;
    } else {
	// move remained data to head.
	for (int i=0; i<restSize; ++i) { //memmove( m_buffer, m_token, (restSize)*sizeof(char) );
	    *(m_buffer+i) = *(m_token+i);
	}
	m_cursor = m_buffer + (m_cursor-m_token);
	m_token = m_buffer;
	m_limit = m_buffer+restSize;
    }
 
    // fill to buffer
    int read_size = m_buffer_size - restSize;
    ifs->read( m_limit, read_size );
    m_limit += ifs->gcount();
 
    return true;
}
 
std::string Scanner::text() {
    return std::string( m_token, m_token+length() );
}
int Scanner::length() {
    return (m_cursor-m_token);
}
int Scanner::lineno() {
    return m_lineno;
}
 
int Scanner::scan(YYSTYPE& yylval) {
 std:
    m_token = m_cursor;
 
    /*!re2c
      re2c:define:YYCTYPE = "char";
      re2c:define:YYCURSOR = m_cursor;
      re2c:define:YYMARKER = m_marker;
      re2c:define:YYLIMIT = m_limit;
      re2c:define:YYFILL:naked = 1;
      re2c:define:YYFILL@len = #;
      re2c:define:YYFILL = "if (!fill(#)) { return 0; }";
      re2c:yyfill:enable = 1;
      re2c:indent:top = 2;
      re2c:indent:string="    ";

      INTEGER                = [1-9][0-9]*;
      WS                     = [ \r\n\t\f];
      ANY_CHARACTER          = [^];

      INTEGER {
      yylval.int_value = atoi(this->text().c_str());
      return TOKEN_INT;
      }
      "+" { return TOKEN_ADD; }
      "-" { return TOKEN_SUB; }
      "*" { return TOKEN_MUL; }
      "/" { return TOKEN_DIV; }
      WS {
      goto std;
      }
      ANY_CHARACTER {
      printf("unexpected character: '%c(%d)'\n", *m_token, *m_token);
      goto std;
      }

    */

}



