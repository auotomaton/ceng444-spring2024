%option noyywrap
%option yylineno
%{
using namespace std;
#include "MyFlexLexer.h"
extern MyFlexLexer *lexer;
%}
digit          [0-9]
idstarter      [A-za-z_]
idcontinuation [A-Za-z_0-9] 
identifier     {idstarter}{idcontinuation}*
ipv4byte       {digit}{digit}?{digit}?
simplenumber   {digit}+("."{digit}*)?
ipv4addr       {ipv4byte}"."{ipv4byte}"."{ipv4byte}"."{ipv4byte}
kw             "while"|"n"("ew"|"ot")
whitesp        [ \n\t\r]*
%%
{simplenumber}    lexer->reportToken("Simple Number");
{kw}              lexer->reportToken("Keyword");
{ipv4addr}        cout << "Recognized ip number (" << lexer->YYText() << ")" << endl;
{whitesp}         cout << "Skipped white space" << endl;
{identifier}      cout << "Recognized identifier (" << lexer->YYText() << ")" << endl;
.                 cout << "Unrecognized (" << lexer->YYText() << ")" << endl;
%%