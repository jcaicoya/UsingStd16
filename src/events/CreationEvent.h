//
//  CreationEvent.h
//  UsingStd16
//


#ifndef CreationEvent_h
#define CreationEvent_h

#include "EventItf.h"

#include <iostream>
#include <string>


class EventFactory;


class CreationEvent: public EventItf
{
public:
    
    void execute() { std::cout << "CreationEvent::execute() - " << _data << std::endl; }

private:
    int _identifier;
    std::string _data;
    
    CreationEvent(const CreationEvent &) = delete;
    CreationEvent & operator=(const CreationEvent &) = delete;

public: //comment when factory used
    explicit CreationEvent(int identifier,
                           std::string data) : _identifier(identifier),
                                               _data(data)
    {}
    
    friend class EventFactory;
    friend std::ostream & operator<<(std::ostream &out, const CreationEvent &creationEvent);
};


std::ostream & operator<<(std::ostream &out, const CreationEvent &creationEvent)
{
    return std::cout << "[identifier:" << creationEvent._identifier << "|data:" << creationEvent._data << "]";
}


#endif /* CreationEvent_h */
