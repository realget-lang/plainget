#pragma once

#include <iostream>
#include <vector>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"

#include "nodes.h"

namespace parser
{

    class Parser
    {
        public:
            Parser(vector<token::Token> toks);
            Parser();

            void advance();

            // For further reading, please refer to grammar.txt
            
            INode* factor();
            INode* term();
            INode* expr();

            INode* parse();

            void clearPointers();



        private:
            token::Token currentToken;
            vector<token::Token> tokensList;

            bool isFinished;
            int tokIdx;



    };

}