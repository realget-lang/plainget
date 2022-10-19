#pragma once

#include <iostream>

#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"


using intFloat = variant<int,float>; //testing
using namespace std;

// Node interface

struct INode {
    virtual void print() = 0;

    virtual string getNodeType() = 0;
};

// Binary operation node stores a binary operation, like a + b, a * b

class BinaryOperationNode : public INode {
private:
    INode* left;
    token::Token oper;
    INode* right;

public:
    BinaryOperationNode(INode*l,token::Token op,INode* r);

    void print() override;
    string getNodeType() override { return "BinaryOperationNode"; }
};

// Number node stores a number, like a float or an int token

class NumberNode : public INode
{
    private:
        token::Token value;

    public:
        NumberNode(token::Token v);

        void print() override;
        string getNodeType() override { return "NumberNode"; }
};

// Unary operation node (oper INT||FLOAT, e.g. -1,-2.5)

class UnaryOperationNode : public INode
{
    private:
        token::Token oper;
        INode* right;

    public:
        UnaryOperationNode(token::Token op, INode* r);

        void print() override;
        string getNodeType() override { return "UnaryOperationNode"; }
};