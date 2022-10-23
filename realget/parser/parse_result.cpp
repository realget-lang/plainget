#include <iostream>

#include "parse_result.h"
#include "nodes.h"
#include "../error/error.h"

namespace parser
{
    ParseResult::ParseResult(errors::Error* err)
    {
        isError = true;
        error = err;
    }

    ParseResult::ParseResult(INode* ast)
    {
        isError = false;
        AST = ast;
    }

    ParseResult& ParseResult::register_(ParseResult newRes)
    {
        if (newRes.isError)
        {
            isError = true;
            error = newRes.error;
            return *this;
        }
        else
        {
            isError = false;
            return *this;
        }
    }

    void ParseResult::err(errors::Error* err)
    {
        isError = true;
        error = err;
    }

    void ParseResult::success(INode* ast)
    {
        isError = false;
        AST = ast;
    }
}