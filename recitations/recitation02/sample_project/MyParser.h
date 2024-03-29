/*
 * MyParser.h
 *
 *  Created on: Mar 24, 2024
 *      Author: erkan
 */

#ifndef MYPARSER_H_
#define MYPARSER_H_

namespace yy
{
   class MyParserBase;
};

// Following enumeration may be useful when downcasting is needed.
enum class JValueType
{
   Str = 0,
   Num = 1,
   Dict = 32,
   Arr = 33
};

class MyFlexLexer;

class MyParser
{
   yy::MyParserBase *base;
   MyFlexLexer      *lexer;

   bool              parseError;
public:
   MyParser();
   ~MyParser();

   void parse(yy::MyParserBase *base, ifstream *is);
   int lex(yy::MyParserBase::value_type *lval);

   void setValue(JValueType t);
   void storeMember();
   void storeArrElement();
   void nameFromId();
   void nameFromStr();

   int getId();
   int getStr();
   int getNumber();

   void setParseError();
   bool getParseError();
};


#endif /* MYPARSER_H_ */
