#include <iostream>
#include "token.h"
#include "tokentype.h"


using namespace std;

using namespace token;

string isLoaded()
{
    return "LOADED!";
}

TokenValue::TokenValue(int a){
    int value = a;
}

TokenValue::TokenValue(string a){
    string value = a;
}

TokenValue::TokenValue(double a){
    double value = a;
}

TokenValue::TokenValue()
{

}




//TokenType type;
//TokenValue value;


Token::Token(TokenType typ, TokenValue val)
{
    type = typ;
    value = val;
}

Token::Token(TokenType typ)
{
    type = typ;
}

Token::Token()
{
    cout << "Token Initialised!" << "\n";
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

        
    
