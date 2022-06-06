#ifndef __TEST__
#define __TEST__

#include <functional>
#include "invokee.h"

class Test 
{
public:

    unsigned int globalReset(int val);
    unsigned int setIPAddress(int val);
};

#endif