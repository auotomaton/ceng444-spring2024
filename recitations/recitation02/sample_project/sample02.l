%option noyywrap
%option yylineno
%{
using namespace std;
#include "sample02.tab.hh"

#undef YY_DECL
#define YY_DECL int MyFlexLexer::lex(yy::MyParserBase::value_type *lval)

#include "MyFlexLexer.h"
#include "MyParser.h"
extern MyParser *parser;


%}
digit          [0-9]
pdigit         [1-9]
wp             {pdigit}{digit}*|"0"
fp             ("0"*{pdigit}+)+
number         (({wp}("."{fp})?)|("."{fp}))(("E"|"e")("+"|"-")?{pdigit}{digit}*)?
idstarter      [A-Za-z_]
idchar         [A-Za-z_0-9]
hexdigit       [0-9a-fA-F]
strchar        [\x23-\xff]|[\x20-\x21]
charashex      "\\x"{hexdigit}{hexdigit}?
escaped        "\\n"|"\\r"|"\\"t|"\\\\"|"\\\""
str            \"({strchar}|{charashex}|{escaped})*\"
identifier     {idstarter}{idchar}*
whitesp        [ \n\t\r\n]*
%%
"{"            {return yy::MyParserBase::token::SOB;}
"}"            {return yy::MyParserBase::token::EOB;}
"["            {return yy::MyParserBase::token::OB;}
"]"            {return yy::MyParserBase::token::CB;}
":"            {return yy::MyParserBase::token::COLON;}
","            {return yy::MyParserBase::token::COMMA;}
{number}       {return parser->getNumber();}
{identifier}   {return parser->getId();}
{str}          {return parser->getStr();}
{whitesp}         
.              {return yy::MyParserBase::token::YYUNDEF;}
%%