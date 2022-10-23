#pragma once

#include <iostream>
#include <variant>
#include <vector>

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
            
            string repr;
            bool hasValue;
            bool isNone();

            

            
    };

    class Token
    {
        public:
            TokenType type;
            TokenValue value;

            string repr;

            string isLoaded();
            
            Token(TokenType typ, TokenValue val, int sPos, int ePos, int l);
            Token(TokenType typ, int sPos, int ePos, int l);
            Token();

            int startPos;
            int endPos;
            int line;

            string toString();

            TokenValue getValue();
            
            TokenType getType();
        
            bool isType(TokenType nType);

            void setType(TokenType nType);
            void setValue(TokenValue nVal);

            

    };
}

