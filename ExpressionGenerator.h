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

#ifndef DYNAMOC_GENERATOR_EXPRESSION
#define DYNAMOC_GENERATOR_EXPRESSION

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "GeneratorInterface.h"

class ExpressionGenerator: public GeneratorInterface<clang::ast_matchers::StatementMatcher>, public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    ExpressionGenerator(std::shared_ptr<GenerateContext> context);
    virtual ~ExpressionGenerator();
    virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result);
    virtual const clang::ast_matchers::StatementMatcher& matcher();
private:
    std::string bindName_;
    clang::ast_matchers::StatementMatcher matcher_;
};

#endif