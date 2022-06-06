#ifndef __INVOKEE__

#define __INVOKEE__

#include <iostream>
#include <functional>
#include <map>

class Invokee
{

public:
    typedef std::function<unsigned int(int val)> TestFunction;
    void RegisterTestHandler(int id, TestFunction handler, std::string summary, std::string details);
    void callHandler(int id);

private:
    std::map<int, TestFunction> handlers;
    std::map<int, std::string> summary;
    std::map<int, std::string> details;
};

#endif