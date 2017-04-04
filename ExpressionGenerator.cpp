//
// Created on Mon Apr 03 2017
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


#include "ExpressionGenerator.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ExprObjC.h"
#include <iostream>
#include <string>

using namespace std;
using namespace clang;
using namespace clang::ast_matchers;

const internal::VariadicDynCastAllOfMatcher<
  Stmt,
  ObjCStringLiteral> objcStringLiteral;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCBoxedExpr> objcBoxedExpr;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCArrayLiteral> objcArrayLiteral;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCDictionaryLiteral> objcDictionaryLiteral;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCEncodeExpr> objcEncodeExpr;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCSelectorExpr> objcSelectorExpr;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCProtocolExpr> objcProtocolExpr;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    ObjCIvarRefExpr> objcIvarRefExpr;

const internal::VariadicDynCastAllOfMatcher<
    Stmt,
    BlockExpr> blockExpr;

ExpressionGenerator::ExpressionGenerator(shared_ptr<GenerateContext> context)
: GeneratorInterface(context), bindName_("expr"), 
matcher_(expr(anyOf(binaryOperator().bind("binaryOperator"), 
                unaryOperator().bind("unaryOperator"),
                integerLiteral().bind("integerLiteral"), 
                floatLiteral().bind("floatLiteral"), 
                objcStringLiteral().bind("objcStringLiteral"), 
                objcBoxedExpr().bind("objcBoxedExpr"), 
                objcArrayLiteral().bind("objcArrayLiteral"), 
                objcDictionaryLiteral().bind("objcDictionaryLiteral"), 
                objcEncodeExpr().bind("objcEncodeExpr"), 
                objcSelectorExpr().bind("objcSelectorExpr"), 
                objcProtocolExpr().bind("objcProtocolExpr"), 
                objcIvarRefExpr().bind("objcIvarRefExpr"), 
                blockExpr().bind("blockExpr"))).bind(bindName_))
{

}

ExpressionGenerator::~ExpressionGenerator()
{

}

void ExpressionGenerator::run(const MatchFinder::MatchResult &result) 
{
    ASTContext *context = result.Context;
    const Stmt *stmt = result.Nodes.getNodeAs<Stmt>(bindName_);
    if(!stmt || !context->getSourceManager().isWrittenInMainFile(stmt->getLocStart()))
        return;

    cout << context_->currentGenMethod->codeBuffer.str() << endl;
}

const StatementMatcher& ExpressionGenerator::matcher()
{
    return matcher_;
}