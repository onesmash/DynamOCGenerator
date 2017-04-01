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

#include "VarDeclGenerator.h"
#include "clang/AST/Decl.h"
#include <iostream>
#include <string>

using namespace std;
using namespace clang;
using namespace clang::ast_matchers;

VarDeclGenerator::VarDeclGenerator(shared_ptr<GenerateContext> context)
: GeneratorInterface(context), bindName_("varDecl"), matcher_(varDecl().bind(bindName_))
{

}

VarDeclGenerator::~VarDeclGenerator()
{

}

void VarDeclGenerator::run(const MatchFinder::MatchResult &result) 
{
    ASTContext *Context = result.Context;
    const VarDecl *vd = result.Nodes.getNodeAs<VarDecl>(bindName_);
    if(!vd || !Context->getSourceManager().isWrittenInMainFile(vd->getLocation()))
        return;
    if(!vd->hasLocalStorage()) {
        llvm::errs() << "error: only support local var " << vd->getNameAsString() << "\n";
        return;
    }
    if(!vd->isLocalVarDecl()) {
        return;
    }
    if(!vd->hasInit ()) {
        context_->currentGenMethod->codeBuffer << "local " << vd->getNameAsString() << endl;
    } else {

    }
    cout << context_->currentGenMethod->codeBuffer.str() << endl;
}

const DeclarationMatcher& VarDeclGenerator::matcher()
{
    return matcher_;
}