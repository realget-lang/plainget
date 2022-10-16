#pragma once

#include <iostream>
#include <list>
#include "token/token.h"
#include "token/tokentype.h"

using namespace std;
using namespace token;

namespace lexer
{
    class Lexer
    {
        public:
            Lexer(string text);
            void advance();

            Token makeNumber();
            list<Token> makeTokens();
            

        private:
            string txt;
            char currentChar;
            int currentIdx;
            list<Token> tokensList;
    };
}