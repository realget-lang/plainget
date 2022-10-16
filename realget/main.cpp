#include <iostream>

#include "lexer/token/token.h"
#include "lexer/token/tokentype.h"

using namespace std;

using namespace token;

int main()
{
    
    // Token tok(INT);
    Token tok = Token(INT_TT);

    




    cout << tok.isType(PLUS_TT) <<"\n";

    //cout << tok.isType(INT) << "\n";

    return 0;
}