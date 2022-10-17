#include <iostream>
#include <list>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"

namespace parser
{

    class Parser
    {
        public:
            Parser();
            void advance();

            


        private:
            token::Token currentToken;
            list<token::Token> tokensList;
            int tokIdx;



    };

}