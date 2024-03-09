# a note on compiling `lex.yy.cc` on macos

## possible problem

normally, we would expect that following commands should work when you are creating and copiling your scanner:
```
flex -+ sample01.l
g++ -o lexer lex.yy.cc sample01.cpp
```

but on the mac system, the clang is used instead of gcc, and for some reason, flex fails include the needed FlexLexer.h file - which causes a conflict and throws the following errors:
```
lex.yy.cc:904:18: error: out-of-line definition of 'LexerInput' does not match any declaration in 'yyFlexLexer'
int yyFlexLexer::LexerInput( char* buf, int /* max_size */ )
                 ^~~~~~~~~~
lex.yy.cc:933:19: error: out-of-line definition of 'LexerOutput' does not match any declaration in 'yyFlexLexer'
void yyFlexLexer::LexerOutput( const char* buf, int size )
                  ^~~~~~~~~~~
2 errors generated.
```
so you cannot compile the scanner program you created.

## solution

one little workaround is adding the following option to you g++ command when compiling:
```
-I/opt/local/include
```
which forces the compiler the include the needed FlexLexer.h header file. 
