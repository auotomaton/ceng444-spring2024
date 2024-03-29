using namespace std;

#include <iostream>
#include <fstream>
#include "sample02.tab.hh"
#include "MyParser.h"
#include "FlexLexer.h"
#include "MyFlexLexer.h"

MyParser *parser;

int main(int argc, char **argv)
{
   ifstream is("sample02.txt");

   if (is.is_open())
   {
      parser=new MyParser();
      yy::MyParserBase *base=new yy::MyParserBase(parser);

      parser->parse(base, &is);

      is.close();

      if (!parser->getParseError())
         cout << "Recognized JSON-Like source." << endl;

      delete parser;
   }
   return 0;
}
