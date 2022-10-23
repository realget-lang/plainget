#include <iostream>
#include <vector>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"

#include "../error/error.h"

#include "parse_result.h"
#include "parser.h"

using namespace parser;
using namespace token;
using namespace errors;

vector<INode*> pointers;
vector<Error*> errs;

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

ParseResult Parser::factor()
{
    Token tok = currentToken;
    int startPos = tok.startPos;
    int endPos = tok.endPos;

    if (tok.isType(INT_TT)||tok.isType(DOUBLE_TT))
    {
        advance();  

        INode* newNode = new NumberNode(tok);


        pointers.push_back(newNode);
        return ParseResult(newNode);
    }
    // Error* e = new errors::SyntaxError(tok.startPos,tok.endPos,"expected an 'int' or a 'float'");
    //cout <<e->toString()<<"\n";

    errors::Error* syn = new errors::SyntaxError(tok.startPos,tok.endPos,"expected an 'int' or a 'float'");
    
    
    //errs.push_back(syn);
    //cout << toErr->toString() << "\n";
    
    return ParseResult(syn);
    
};

ParseResult Parser::term()
{
    ParseResult left = factor();
    //cout << "still valid \n";
    if (left.isError) // If it errors then just return the error
    {
        return left;
    }
    

    while (currentToken.isType(MUL_TT)||currentToken.isType(DIV_TT))
    {
        Token oper_tok = currentToken;
        advance();
        ParseResult right = factor();

        if (right.isError) //If it errors, just return the error
        {
            return right;
        }

        //INode* nodeCreated = new BinaryOperationNode(left,oper_tok,right);
        INode* newNode = new BinaryOperationNode(left.getAst(),oper_tok,right.getAst());
        pointers.push_back(newNode);

        left = ParseResult(newNode);
    }
    return left;
};

ParseResult Parser::expr()
{
    ParseResult left = term();

    if (left.isError)
    {
        return left;
    }

    while (currentToken.isType(PLUS_TT)||currentToken.isType(MINUS_TT))
    {
        Token oper_tok = currentToken;
        advance();
        ParseResult right = term();
        

        if (right.isError)
        {
            return right;
        }

        //INode* nodeCreated = new BinaryOperationNode(left,oper_tok,right);
        
        INode* newNode = new BinaryOperationNode(left.getAst(),oper_tok,right.getAst());
        pointers.push_back(newNode);
        
        left = ParseResult(newNode);
    }
    return left;
}

ParseResult Parser::parse()
{
    ParseResult result = expr();
    INode* ast = result.getAst();
    if (result.isError == false)
    {
        cout << ast->getNodeType()<<"\n";
    }
    

    return result;
}

void Parser::clearPointers()
{
    for(std::vector<INode*>::size_type i = 0; i != pointers.size(); i++) {
        free(pointers[i]);

        pointers[i] = NULL;
    }

    for(std::vector<Error*>::size_type i = 0; i != errs.size(); i++) {
        free(errs[i]);
        
        errs[i] = NULL;
    }
}