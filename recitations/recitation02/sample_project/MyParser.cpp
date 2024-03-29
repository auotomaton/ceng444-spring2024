using namespace std;

#include <iostream>
#include <fstream>
#include <string.h>
#include "sample02.tab.hh"
#include "MyParser.h"
#include "FlexLexer.h"
#include "MyFlexLexer.h"

MyParser::MyParser()
{
   parseError=false;
   base=nullptr;
   lexer=nullptr;
}

MyParser::~MyParser()
{
   // Clean-up
   delete lexer;
   delete base;
}

int MyParser::lex(yy::MyParserBase::value_type *lval)
{
   return lexer->lex(lval);
}

void MyParser::parse(yy::MyParserBase *base, ifstream *is)
{
   this->base=base;
   lexer=new MyFlexLexer();
   lexer->switch_streams(is);
   base->parse();
}

int MyParser::getId()
{
   return yy::MyParserBase::token::ID;
}

int MyParser::getStr()
{
   return yy::MyParserBase::token::STR;
}

int MyParser::getNumber()
{
   return yy::MyParserBase::token::NUM;
}

void MyParser::nameFromId()
{
}

void MyParser::nameFromStr()
{
}

void MyParser::setValue(JValueType t)
{
   // Mock action using recognized value type
   switch (t)
   {
      case JValueType::Str:
         break;
      case JValueType::Num:
         break;
      case JValueType::Dict:
         break;
      case JValueType::Arr:
         break;
   }
}

void MyParser::storeMember()
{
   // Mock action to store recognized member
}

void MyParser::storeArrElement()
{
   // Mock action to store array element
}

void MyParser::setParseError()
{
   parseError=true;
}

bool MyParser::getParseError()
{
   return parseError;
}

extern MyParser *parser;

void yy::MyParserBase::error(const std::string &msg)
{
   parser->setParseError();
   cout << "Not recognized!" << endl;
}
