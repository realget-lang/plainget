#include <iostream>

#include "error.h"

using namespace errors;

Error& Error::setPos(int start, int end)
{
    startPos = start;
    endPos = end;
    return *this;
}

IllegalCharacterError::IllegalCharacterError(int start, int end, string det)
{
    startPos = start;
    endPos = end;
    details = det;
}

SyntaxError::SyntaxError(int start, int end, string det)
{
    startPos = start;
    endPos = end;
    details = det;
}