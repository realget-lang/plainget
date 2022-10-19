#pragma once

#include <iostream>
#include <vector>
#include "token/token.h"
#include "token/tokentype.h"

#include "../error/error.h"

using namespace std;
using namespace token;

namespace lexer
{
    class LexResult
    {
        public:
            errors::Error* error;
            vector<Token> tokensList;
            bool isError;

            LexResult(vector<Token> tokList);
            LexResult(errors::Error* err);
            LexResult();

            LexResult& register_(LexResult newRes);
            void err(errors::Error* err);
            void success(vector<Token> tokList);

    };

    class Lexer
    {
        public:
            Lexer(string text);
            void advance();

            Token makeNumber();
            LexResult makeTokens();
            

        private:
            string txt;
            char currentChar;
            int currentIdx;
            vector<Token> tokensList;
    };
}