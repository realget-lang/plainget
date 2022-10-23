#pragma once

#include <iostream>

using namespace std;

namespace errors
{
    class Error
    {
        public:
            virtual string toString() = 0;

            string details;

            int startPos;
            int endPos;
            int line;

            Error& setPos(int start, int end);
    };

    class IllegalCharacterError : public Error
    {
        public:
            IllegalCharacterError(int start, int end, string det);

            string toString() override
            {
                return "IllegalCharacterError: What the character '"+details+"' doin at col:"+to_string(startPos)+" ln:"+to_string(line);
            }
    };

    class SyntaxError : public Error
    {
        public:

            SyntaxError(int start, int end, string det);

            string toString() override
            {
                return "SyntaxError: "+details+" at col:"+to_string(startPos)+" ln:"+to_string(line);
            }
    };
}