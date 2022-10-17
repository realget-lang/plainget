#include <iostream>
#include <cstdio>

#include "lexer/token/token.h"
#include "lexer/token/tokentype.h"

#include "lexer/lexer.h"

using namespace std;

using namespace token;

std::ostream &operator<<(ostream &os, const list<token::Token> &list)
{   
    os << "[";
    for (auto const &i: list) {
        os << i.tokString << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    
    // Token tok(INT);
    Token tok = Token(INT_TT);


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