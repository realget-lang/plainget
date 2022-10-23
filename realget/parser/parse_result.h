#pragma once

#include "parse_result.h"
#include "nodes.h"
#include "../error/error.h"

namespace parser
{
    class ParseResult
    {
        public:
            INode* AST;
            errors::Error* error;
            bool isError;

            ParseResult(errors::Error* err);
            ParseResult(INode* ast);
            ParseResult();

            ParseResult& register_(ParseResult newRes);
            INode* getAst();
            void err(errors::Error* err);
            void success(INode* ast);
    };
}