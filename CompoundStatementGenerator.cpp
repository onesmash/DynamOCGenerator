//
// Created on Tue Mar 28 2017
//
// The MIT License (MIT)
// Copyright @ 2017 Xu Hui
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial
// portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//


#include "CompoundStatementGenerator.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/Stmt.h"
#include <iostream>
#include <string>

using namespace std;
using namespace clang;
using namespace clang::ast_matchers;

CompoundStatementGenerator::CompoundStatementGenerator(shared_ptr<GenerateContext> context)
: GeneratorInterface(context), bindName_("compoundStmt"), matcher_(compoundStmt().bind(bindName_))
{

}

CompoundStatementGenerator::~CompoundStatementGenerator()
{

}

void CompoundStatementGenerator::run(const MatchFinder::MatchResult &result) 
{
    ASTContext *context = result.Context;
    const CompoundStmt *stmt = result.Nodes.getNodeAs<CompoundStmt>(bindName_);
    if(!stmt || !context->getSourceManager().isWrittenInMainFile(stmt->getLocStart()))
        return;
    //stmt->dump();
}

const StatementMatcher& CompoundStatementGenerator::matcher()
{
    return matcher_;
}