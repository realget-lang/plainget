#include <iostream>
#include <vector>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"

#include "parser.h"

using namespace parser;
using namespace token;

vector<INode*> pointers;

Parser::Parser(vector<Token> toks)
{
    tokensList = toks;
    tokIdx = 0;
    currentToken = tokensList[tokIdx];
    isFinished = false;
}   

void Parser::advance()
{
    if (isFinished == false)
    {
        if (tokIdx < tokensList.size()-1)
        {
            tokIdx += 1;
            currentToken = tokensList[tokIdx];
        }
        else { isFinished = true; }
    }
}

INode* Parser::factor()
{
    Token tok = currentToken;

    if (tok.isType(INT_TT)||tok.isType(DOUBLE_TT))
    {
        advance();  

        INode* newNode = new NumberNode(tok);

        pointers.push_back(newNode);
        return newNode;
    }
    cout << "you dun goof 😎 " <<"\n";
};

INode* Parser::term()
{
    INode* left = factor();
    

    while (currentToken.isType(MUL_TT)||currentToken.isType(DIV_TT))
    {
        Token oper_tok = currentToken;
        advance();
        INode* right = factor();

        //INode* nodeCreated = new BinaryOperationNode(left,oper_tok,right);
        INode* newNode = new BinaryOperationNode(left,oper_tok,right);
        pointers.push_back(newNode);

        left = newNode;
    }
    return left;
};

INode* Parser::expr()
{
    INode* left = term();

    while (currentToken.isType(PLUS_TT)||currentToken.isType(MINUS_TT))
    {
        Token oper_tok = currentToken;
        advance();
        INode* right = term();

        //INode* nodeCreated = new BinaryOperationNode(left,oper_tok,right);
        
        INode* newNode = new BinaryOperationNode(left,oper_tok,right);
        pointers.push_back(newNode);
        
        left = newNode;
    }
    return left;
}

INode* Parser::parse()
{
    INode* result = expr();
    cout << result->getNodeType()<<"\n";

    return result;
}

void Parser::clearPointers()
{
    for(std::vector<INode*>::size_type i = 0; i != pointers.size(); i++) {
        free(pointers[i]);

        pointers[i] = NULL;
    }
}