#include <iostream>
#include <cstdio>

#include "lexer/token/token.h"
#include "lexer/token/tokentype.h"

#include "lexer/lexer.h"

using namespace std;

using namespace token;

int main()
{
    
    // Token tok(INT);
    Token tok = Token(INT_TT);


    string input;

    cout << "Realget Terminal, enter 'quit()' to quit." << "\n\n";

    cout << "Realget >> ";
    while (getline(cin, input)) {
        

        cout << input;
        cout << "\n";

        lexer::Lexer(input).makeTokens();

        if (input == "quit()")
        {
            break;
        }
        cout << "Realget >> ";
    }

    //cout << tok.isType(INT) << "\n";

    return 0;
}