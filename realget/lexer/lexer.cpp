#include <iostream>
#include <list>
#include <ctype.h>

#include "token/token.h"
#include "token/tokentype.h"
#include "lexer.h"


using namespace std;
using namespace token;

int deadIndex = -69;

namespace lexer
{
    
    Lexer::Lexer(string text)
    {
        txt = text;
        currentIdx = 0;

        currentChar = txt[currentIdx];
    }

    void Lexer::advance()
    {
        
        //cout << currentChar << "\n";
        if (currentIdx < txt.length()-1)
        {
            currentIdx++;
            currentChar = txt[currentIdx];
        }
        else
        {
            
            currentIdx = deadIndex;
        }
    }

    list<Token> Lexer::makeTokens()
    {
        
        while (currentIdx != deadIndex)
        {
            switch (currentChar)
            {
                case '+':
                    tokensList.push_back(Token(PLUS_TT));
                    advance();
                    break;
                case '-':
                    tokensList.push_back(Token(MINUS_TT));
                    advance();
                    break;
                case '*':
                    tokensList.push_back(Token(MUL_TT));
                    advance();
                    break;
                case '/':
                    tokensList.push_back(Token(DIV_TT));
                    advance();
                    break;
                default:
                    if (isdigit(currentChar))
                    {
                        
                        Token numTok = makeNumber();

                        tokensList.push_back(numTok);
                    }
                    else if (currentChar == '\t' || currentChar == ' ')
                    {
                        advance();
                    }
                    else
                    {
                        advance();
                    }
                    
            }
            
        }

        //cout << "done making tokens!" << "\n";
        
        return tokensList;
    }

    Token Lexer::makeNumber()
    {
        string number = "";
        bool hasDot = false;

        while ((isdigit(currentChar) || currentChar == '.') && currentIdx != deadIndex)
        {
            number += currentChar;
            advance();
        }
        cout << "Number making ended with "<<number << "\n";

        if (hasDot)
        {
            return Token(DOUBLE_TT,stod(number));
        }
        return Token(INT_TT,stoi(number));
    }
    
            

        
    
}