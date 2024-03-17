#include <iostream>
#include <fstream>
#include "FlexLexer.h"
#include "MyFlexLexer.h"
using namespace std;

void MyFlexLexer::reportToken(const char *label)
{
   cout << "Recognized " << label << "(" << YYText() << ") line:" << yylineno << endl;
}

MyFlexLexer *lexer=new MyFlexLexer();

int main(int argc, char **argv)
{
   ifstream is("sample01.txt");

   if (is.is_open())
   {
      lexer->switch_streams(&is);
      while (lexer->yylex() != 0)
         ;

      is.close();
   }
   return 0;
}
