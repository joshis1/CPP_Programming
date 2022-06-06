
#include <iostream>
#include "test.h"

unsigned int Test::globalReset(int val)
{

    std::cout << "global Reset invoked" << std::endl;
    return 0;
}
unsigned int Test::setIPAddress(int val)
{
    std::cout << "Set IP Address Invoked" << std::endl;
    return 0;
}