#ifndef DYNAMOC_GENERATOR_INTERFACE
#define DYNAMOC_GENERATOR_INTERFACE

#include "GenerateContext.h"
#include <memory>

template <typename MatcherT>
class GeneratorInterface {
public:
    typedef MatcherT MatcherType;
    GeneratorInterface(std::shared_ptr<GenerateContext> context)
    {
        context_ = context;
    }

    GeneratorInterface(const GeneratorInterface<MatcherT>& interface);
    virtual ~GeneratorInterface() = 0;
    virtual const MatcherType& matcher() = 0;
    std::shared_ptr<GenerateContext> context()
    {
        return context_;
    }
protected:
    std::shared_ptr<GenerateContext> context_;
};

#include "GeneratorInterfaceImp.h"

#endif