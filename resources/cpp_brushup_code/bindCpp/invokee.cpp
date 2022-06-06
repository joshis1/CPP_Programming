#include "invokee.h"

void Invokee::RegisterTestHandler(int id, TestFunction handler, std::string summary, std::string details)
{

    this->handlers[id] = handler;
    this->summary[id] = summary;
    this->details[id] = details;
}

void Invokee::callHandler(int id)
{
    auto handler = handlers.find(id);
    if (handler != handlers.end())
    {
        std::cout << "Found the handler --" << std::endl;
        handler->second(1);
    }
}