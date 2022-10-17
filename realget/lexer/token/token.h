#pragma once

#include <iostream>
#include <variant>
#include <list>

#include "tokentype.h"

using namespace std;

namespace token
{
    string isLoaded();
    
    class NoneValue
    {
    };

    class TokenValue
    {
        public:
            variant<int,string,float,NoneValue> value;

            TokenValue(int a);
            TokenValue(string a);
            TokenValue(float a);
            TokenValue();

            // Doesn't have a value
            
            string tokRepr;
            bool hasValue;
            bool isNone();

            

            
    };

    class Token
    {
        public:
            TokenType type;
            TokenValue value;

            string tokString;

            string isLoaded();
            
            Token(TokenType typ, TokenValue val);
            Token(TokenType typ);
            Token();

            string toString();

            TokenValue getValue();
            
            TokenType getType();
        
            bool isType(TokenType nType);

            void setType(TokenType nType);
            void setValue(TokenValue nVal);

            

    };
}

