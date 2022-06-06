#include <iostream>
#include "test.h"
#include "invokee.h"
#include <memory>
#include <functional>

// beautify using clang-format in Vscode.


int main(int argc, char **argv)
{
    auto *invokeTest = new Invokee();
    Test *test = new Test();

    std::string summary = "global reset summary";
    std::string details = "global reset details";

    //Basically there are two object from different class - InvokeTest --> does the registration of the handler.
    // Now the InvokeTest has to call the member function of class object - Test.
    // ?? How it can do - it can do using bind - basically, the this pointer of Test class is available to invokeTest
    // therefore invokeTest can simply invoke the member function of test object.
    // until the test point is valid, it can use it to invoke the method of it ?? --> Is it really correct?

    delete(test);  //experiment deleted the test pointer.
    test= nullptr;  // explicity set to nullptr
    // still it works?? how come ??

    invokeTest->RegisterTestHandler(1, std::bind(&Test::globalReset, test, std::placeholders::_1), summary, details);
    invokeTest->callHandler(1);

    

    return 0;
}