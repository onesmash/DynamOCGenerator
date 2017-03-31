
//
// Created on Wed Mar 29 2017
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


#include "ObjCMethodDeclGenerator.h"
#include "clang/AST/DeclObjC.h"
#include <iostream>
#include <string>

using namespace std;
using namespace clang;
using namespace clang::ast_matchers;

const internal::VariadicDynCastAllOfMatcher<
  Decl,
  ObjCMethodDecl> objcMethodDecl;

ObjCMethodDeclGenerator::ObjCMethodDeclGenerator(std::shared_ptr<GenerateContext> context)
: GeneratorInterface(context), bindName_("ObjCMethodDecl"), matcher_(objcMethodDecl().bind(bindName_))
{

}

ObjCMethodDeclGenerator::~ObjCMethodDeclGenerator()
{

}

void ObjCMethodDeclGenerator::run(const MatchFinder::MatchResult &result) 
{
    ASTContext *context = result.Context;
    const ObjCMethodDecl *md = result.Nodes.getNodeAs<ObjCMethodDecl>(bindName_);
    if(!md || !context->getSourceManager().isWrittenInMainFile(md->getLocation()) || !md->hasBody())
        return;
    if(context_->currentGenMethod != nullptr) {
        context_->addMethod(*(context_->currentGenMethod));
        context_->currentGenMethod = nullptr;
    }
    context_->currentGenMethod = std::make_shared<DynamOCMethod>();
    context_->currentGenMethod->name = md->getNameAsString();
    context_->currentGenMethod->typeEncode = context->getObjCEncodingForMethodDecl(md, true);
    context_->currentGenMethod->isInstanceMethod = md->isInstanceMethod(); 
    for (auto iter = md->param_begin(); iter != md->param_end(); iter++) {
        string name = (*iter)->getNameAsString();
        context_->currentGenMethod->paramNames.push_back(name);
        cout << name << endl;
    }
}

const DeclarationMatcher& ObjCMethodDeclGenerator::matcher()
{
    return matcher_;
}