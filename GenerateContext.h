//
// Created on Thu Mar 30 2017
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

#ifndef DYNAMOC_GENERATOR_GENERATECONTEXT
#define DYNAMOC_GENERATOR_GENERATECONTEXT

#include "DynamOCClassModel.h"
#include "DynamOCIVar.h"
#include "DynamOCProperty.h"
#include "DynamOCMethod.h"
#include "clang/ASTMatchers/Dynamic/Diagnostics.h"
#include <memory>
#include <vector>

class ObjCMethod;

class GenerateContext {
public:
    GenerateContext() {}
    ~GenerateContext() {}
    std::shared_ptr<DynamOCMethod> currentGenMethod;

    void addIVar(const DynamOCIVar& ivar);
    void addPropery(const DynamOCProperty& property);
    void addMethod(const DynamOCMethod& method);

    void pushCodeBlockEndLoc(CodeBlockType type, clang::ast_matchers::dynamic::SourceLocation loc);
    void checkMatchLocation(clang::ast_matchers::dynamic::SourceLocation loc);

private:
    enum CodeBlockType {
        kCodeBlockTypeParen,
        kCodeBlockTypeCompound
    };
    DynamOCClassModel model_;
    std::vector<std::pair<CodeBlockType, clang::ast_matchers::dynamic::SourceLocation> > codeBlockEndLocs_;
};

#endif