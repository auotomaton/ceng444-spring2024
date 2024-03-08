#include <iostream>
#include <fstream>
#include "FlexLexer.h"
#include "MyFlexLexer.h"
using namespace std;

void MyFlexLexer::reportToken(const char *label)
{
   cout << "Recognized " << label << "(" << YYText() << ") line:" << yylineno << endl;
}

FlexLexer *lexer=new MyFlexLexer();

int main(int argc, char **argv)
{
   ifstream is("sample01.txt");

   if (is.is_open())
   {
      while (lexer->yylex(&is) != 0)
         ;

      is.close();
   }
   return 0;
}
