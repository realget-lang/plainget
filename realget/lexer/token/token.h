#pragma once

#include <iostream>
#include "tokentype.h"

using namespace std;

namespace token
{
    string isLoaded();
    
    

    class TokenValue
    {
        public:
            TokenValue(int a);
            TokenValue(string a);
            TokenValue(double a);
            TokenValue();
    };

    class Token
    {
        public:
            TokenType type;
            TokenValue value;

            string isLoaded();
            
            Token(TokenType typ, TokenValue val);
            Token(TokenType typ);
            Token();

            TokenValue getValue();
            
            TokenType getType();
        
            bool isType(TokenType nType);

            void setType(TokenType nType);

            void setValue(TokenValue nVal);
            

    };
}