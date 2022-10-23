#include <iostream>
#include <vector>
#include <ctype.h>

#include "token/token.h"
#include "token/tokentype.h"
#include "lexer.h"

#include "../error/error.h"


using namespace std;
using namespace token;
using namespace errors;

int deadIndex = -69;

namespace lexer
{
    LexResult::LexResult(vector<Token> tokList)
    {
        tokensList = tokList;
        isError = false;
    }

    LexResult::LexResult(errors::Error* err)
    {
        error = err;
        isError = true;
    }

    LexResult::LexResult()
    {
        isError = false;
    }

    LexResult& LexResult::register_(LexResult newRes)
    {
        if (newRes.isError)
        {
            error = newRes.error;
            isError = true;
        }
        return *this;
    }

    void LexResult::err(errors::Error* err)
    {
        error = err;
        isError = true;
    }

    void LexResult::success(vector<Token> tokList)
    {
        tokensList = tokList;
        isError = false;
    }

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

    LexResult Lexer::makeTokens()
    {
        
        while (currentIdx != deadIndex)
        {
            switch (currentChar)
            {
                case '+':
                    tokensList.push_back(Token(PLUS_TT,currentIdx+1,currentIdx+1,1));
                    advance();
                    break;
                case '-':
                    tokensList.push_back(Token(MINUS_TT,currentIdx+1,currentIdx+1,1));
                    advance();
                    break;
                case '*':
                    tokensList.push_back(Token(MUL_TT,currentIdx+1,currentIdx+1,1));
                    advance();
                    break;
                case '/':
                    tokensList.push_back(Token(DIV_TT,currentIdx+1,currentIdx+1,1));
                    advance();
                    break;
                default:
                    if (isdigit(currentChar))
                    {
                        
                        LexResult lexres = makeNumber();

                        if (lexres.isError)
                        {
                            return lexres;
                        }
                        Token numTok = lexres.tokensList[0];

                        tokensList.push_back(numTok);
                    }
                    else if (currentChar == '\t' || currentChar == ' ')
                    {
                        advance();
                    }
                    else
                    {
                        LexResult l;

                        l.err(new IllegalCharacterError(currentIdx+1,currentIdx+1,string(1,currentChar)));

                        return l;
                    }
                    
            }
            
        }

        //cout << "done making tokens!" << "\n";
        LexResult res(tokensList);

        return res;
    }

    LexResult Lexer::makeNumber()
    {
        int start = currentIdx;
        string number = "";
        bool hasDot = false;

        while ((isdigit(currentChar) || currentChar == '.') && currentIdx != deadIndex)
        {
            number += currentChar;
            if (currentChar == '.')
            {
                if (hasDot == true)
                {
                    return LexResult(new SyntaxError(currentIdx+1,currentIdx+1,"are you trying to write an IP address?"));
                }
                else
                {
                    hasDot = true;
                }   
            }
            advance();
        }
        //cout << "Number making ended with "<<number << "\n";
        
        vector<Token> toRet;

        if (hasDot)
        {
            toRet.push_back(Token(DOUBLE_TT,stof(number),start,currentIdx+1,1 /* line 1 */));
            return LexResult(toRet);
        }
        toRet.push_back(Token(INT_TT,stoi(number),start,currentIdx+1,1 /* line 1 */));
        return LexResult(toRet);
        // return Token(INT_TT,stoi(number),start,currentIdx+1,1 /* line 1 */);
    }
    
            

        
    
}