#include <iostream>
#include <cstdio>

#include "lexer/token/token.h"
#include "lexer/token/tokentype.h"

#include "parser/parse_result.h"
#include "parser/nodes.h"

#include "parser/parser.h"
#include "lexer/lexer.h"


#include <chrono>
using namespace std::chrono;

using namespace std;

using namespace token;

std::ostream &operator<<(ostream &os, const vector<token::Token> &vector)
{   
    os << "[";
    for (auto const &i: vector) {
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
            auto start = high_resolution_clock::now();
            lexer::LexResult res = lexer::Lexer(input).makeTokens();
            
            if (res.isError)
            {
                // Checks for errors
                // 'Realget >>' is 10
                int charPos = 10 + res.error->startPos;

                // Shows the arrow point first
                cout <<string(charPos,'-')<<"^"<<"\n\n";

                // Then shows the error
                cout<<res.error->toString()<<"\n";



            }
            else
            {
                vector<Token> tokensList = res.tokensList;

                

                parser::Parser parserObj = parser::Parser(tokensList);

                //cout << "parsing: \n";
                parser::ParseResult ast = parserObj.parse();

                //cout << "parse err:" << ast.isError<<"\n";

                if (ast.isError == false)
                {
                    ast.getAst()->print();
                }
                else
                {
                    
                    int charPos = 10 + ast.error->startPos;

                    // Shows the arrow point first
                    cout <<string(charPos,'-')<<"^"<<"\n\n";

                    // Then shows the error
                    cout<<ast.error->toString()<<"\n";
                }

                cout << "\nTokens created: "<<tokensList;
                cout << "\n";
            
                parserObj.clearPointers();
            
                
                auto stop = high_resolution_clock::now();

                auto duration = duration_cast<microseconds>(stop - start);

                cout <<"\nThat took: "<< duration.count()<<" microseconds" << endl;
            }
            

            
        }
        //Continues the console
        
        cout << "Realget >> ";
        
    }

    //cout << tok.isType(INT) << "\n";

    return 0;
}