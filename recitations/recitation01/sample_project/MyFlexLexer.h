/*
 * MyFlexLexer.h
 *
 *  Created on: Feb 29, 2024
 *      Author: erkan
 */

#ifndef MYFLEXLEXER_H_
#define MYFLEXLEXER_H_

class MyFlexLexer : public yyFlexLexer
{
public:
   void reportToken(const char *label);
};

#endif /* MYFLEXLEXER_H_ */
