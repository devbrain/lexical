#include <sstream>
#include <cassert>
#include <cstdlib>
#include "scanner.h"



extern "C" void ParseInit(void *yypParser);
extern "C" void *ParseAlloc(void *(*mallocProc)(size_t));
extern "C" void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
			  );
extern "C" void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  YYSTYPE yyminor,       /* The value for the token */
  ParserState* extra               /* Optional %extra_argument parameter */
		      );
int main() {
    YYSTYPE yylval;

    std::istringstream is("1+2");
    
    Scanner scanner(&is);
    void *pParser = ParseAlloc(malloc);
    int tokenID;

#if 0
    ParseTrace(stderr, (char*)"[Parser] >> ");
#endif

    ParserState state;
    state.result = 0;
    // scanner.scan return 0 when get EOF.
    while (tokenID = scanner.scan(yylval)) {
        Parse(pParser, tokenID, yylval, &state);
    }
    Parse(pParser, 0, yylval, &state);
    ParseFree(pParser, free);

    printf("RESULT: %d\n", state.result);
    return 0;
}

