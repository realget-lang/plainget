#include <iostream>
#include <cstdio>

#include "lexer/token/token.h"
#include "lexer/token/tokentype.h"

#include "parser/nodes.h"

#include "lexer/lexer.h"

using namespace std;

using namespace token;

std::ostream &operator<<(ostream &os, const list<token::Token> &list)
{   
    os << "[";
    for (auto const &i: list) {
        os << i.repr << ", ";
    }
    os << "]";
    return os;
}

int main()
{ 
    /*
    NumberNode a(Token(INT_TT,TokenValue(234)));
    NumberNode b(Token(INT_TT,TokenValue(123)));

    BinaryOperationNode cNode(&a,Token(PLUS_TT),&b);

    BinaryOperationNode cNode2(&cNode,Token(PLUS_TT),&b);
    

    cNode.print();
    cout<<"\n\n";
    cNode2.print();
    cout<<" is CNODE 2\n\n";
    
    */


    string input;

    cout << "Realget Terminal, enter 'quit()' to quit." << "\n\n";

    cout << "Realget >> ";
    while (getline(cin, input)) {
        

        

        if (input == "quit()")
        {
            break;
        }

        if (input != "") //checks for emptiness
        {
            list<Token> tokensList = lexer::Lexer(input).makeTokens();

            cout << "Tokens created: "<<tokensList;
            cout << "\n";
            
        }
        //Continues the console
        
        cout << "Realget >> ";
        
    }

    //cout << tok.isType(INT) << "\n";

    return 0;
}