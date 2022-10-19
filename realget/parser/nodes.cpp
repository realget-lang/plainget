#include <iostream>
#include <variant>

#include "nodes.h"
#include "../lexer/token/token.h"
#include "../lexer/token/tokentype.h"

BinaryOperationNode::BinaryOperationNode(INode*l,token::Token op,INode* r)
{
    left = l;
    oper = op;
    right = r;
}

void BinaryOperationNode::print() 
{
    std::cout << "( ";
    left->print();
    std::cout << ", ";
    std::cout<<oper.repr;
    std::cout << ", ";
    right->print();
    std::cout << " )";
}

NumberNode::NumberNode(token::Token v)
{
    value = v;
}

void NumberNode::print()
{
    std::cout << value.repr;
}

UnaryOperationNode::UnaryOperationNode(token::Token op, INode* r)
{
    right = r;
    oper = op;
}

void UnaryOperationNode::print()
{
    std::cout << "( ";
    std::cout<<oper.repr;
    std::cout << ", ";
    right->print();
    std::cout << " )";

}