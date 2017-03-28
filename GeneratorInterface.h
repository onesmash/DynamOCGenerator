#ifndef DYNAMOC_GENERATOR_INTERFACE
#define DYNAMOC_GENERATOR_INTERFACE

template <typename MatcherT>
class GeneratorInterface {
public:
    virtual ~GeneratorInterface() = 0;
    virtual const MatcherT& matcher() = 0;
};

#include "GeneratorInterfaceImp.h"

#endif