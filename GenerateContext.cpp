//
// Created on Fri Mar 31 2017
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

#include "GenerateContext.h"
using namespace std;

void GenerateContext::addIVar(const DynamOCIVar& ivar)
{

}

void GenerateContext::addPropery(const DynamOCProperty& property)
{

}

void GenerateContext::addMethod(const DynamOCMethod& method)
{
    model_.methods.insert({method.name, method});
}

void GenerateContext::pushCodeBlockEndLoc(CodeBlockType type, clang::ast_matchers::dynamic::SourceLocation loc)
{
    codeBlockEndLocs_.push_back({type, loc});
}

void GenerateContext::checkMatchLocation(clang::ast_matchers::dynamic::SourceLocation loc)
{
    if(codeBlockEndLocs_.size()) {
        auto codeBlock = codeBlockEndLocs_.back();
        if(loc.Column > codeBlock.second.Colum && loc.Line >= codeBlock.second.Line) {
            if(codeBlock.first == kCodeBlockTypeParen) {
                
            } else if(codeBlock.first == kCodeBlockTypeCompound) {
                
            }
        }
    }
}