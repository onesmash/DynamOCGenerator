#ifndef DYNAMOC_GENERATOR_INTERFACE
#define DYNAMOC_GENERATOR_INTERFACE

template <typename MatcherT>
class GeneratorInterface {
public:
    typedef MatcherT MatcherType;
    virtual ~GeneratorInterface() = 0;
    virtual const MatcherType& matcher() = 0;
};

#include "GeneratorInterfaceImp.h"

#endif