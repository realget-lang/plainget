#pragma once

#include <iostream>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"


using intFloat = variant<int,float>; //testing
using namespace std;

struct INode {
    virtual void print() = 0;
};

class BinaryOperationNode : public INode {
private:
    INode* left;
    token::Token oper;
    INode* right;

public:
    BinaryOperationNode(INode*l,token::Token op,INode* r);

    void print() override;
};

class NumberNode : public INode
{
    private:
        token::Token value;

    public:
        NumberNode(token::Token v);

        void print() override;
};

class UnaryOperationNode : public INode
{
    private:
        token::Token oper;
        INode* right;

    public:
        UnaryOperationNode(token::Token op, INode* r);

        void print() override;
};