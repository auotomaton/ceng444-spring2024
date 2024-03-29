%language "c++"
%define api.parser.class {MyParserBase}

%{
using namespace std;
#include <iostream>
#include <fstream>
%}
%code requires
{
class MyParser;
};

%code 
{
   #include "MyParser.h"
   #define yylex(x) driver->lex(x)
   
   extern MyParser *parser;
}

%parse-param {MyParser *driver} 
%start jvalue

%token SOB
%token EOB
%token OB
%token CB
%token ID
%token STR
%token NUM
%token COLON
%token COMMA

%%
   
dictionary
   : SOB memberlist EOB    
   ;
   
array
   : OB valuelist CB;

memberlist
   : member 
   | member COMMA memberlist
   | ;
   
valuelist
   : arrelement
   | arrelement COMMA valuelist
   | ;
   
arrelement: jvalue         {parser->storeArrElement();}
   
member
   : name COLON jvalue     {parser->storeMember();}
   ;
    
name 
   : ID                    {parser->nameFromId();}
   | STR                   {parser->nameFromStr();}
   ;      

jvalue 
   : STR          {parser->setValue(JValueType::Str);}
   | NUM          {parser->setValue(JValueType::Num);}
   | dictionary   {parser->setValue(JValueType::Dict);}
   | array        {parser->setValue(JValueType::Arr);}
   ;
 
%%