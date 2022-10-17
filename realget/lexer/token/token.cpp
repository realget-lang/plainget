#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>


#include "token.h"
#include "tokentype.h"




using namespace std;

using namespace token;

string isLoaded()
{
    return "LOADED!";
}

TokenValue::TokenValue(int a){
    value = a;
    tokRepr = to_string(a);
    hasValue = true;
}

TokenValue::TokenValue(string a){
    value = a;
    tokRepr = a;
    hasValue = true;
}

TokenValue::TokenValue(float a){
    value = a;
    //cout << "FLOATTOKEN:"<<a<<"\n";
    tokRepr = to_string(a);
    hasValue = true;
}

TokenValue::TokenValue()
{  
    value = NoneValue();
    tokRepr = "NONE";
    hasValue = false;
}



bool TokenValue::isNone()
{
    return hasValue;
}




//TokenType type;
//TokenValue value;


Token::Token(TokenType typ, TokenValue val)
{
    type = typ;
    value = val;

    tokString = "TT="+to_string(typ)+"T"+":VAL="+val.tokRepr;
}

Token::Token(TokenType typ)
{
    type = typ;
    value = TokenValue();

    tokString = "TT="+to_string(typ)+"T";
}

Token::Token()
{
    tokString = "😎";
}


TokenValue Token::getValue()
{
    return Token::value;
}

TokenType Token::getType()
{
    return Token::type;
}



bool Token::isType(TokenType nType)
{
    return (type == nType);
}

void Token::setType(TokenType nType)
{
    type = nType;
}

void Token::setValue(TokenValue nVal)
{
    value = nVal;
}

        