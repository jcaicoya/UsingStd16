//
//  UpdateEvent.h
//  UsingStd16
//


#ifndef UpdateEvent_h
#define UpdateEvent_h

#include "EventItf.h"

#include <iostream>
#include <string>


class EventFactory;


class UpdateEvent: public EventItf
{
public:
    
    void execute() { std::cout << "UpdateEvent::execute() - " << *this << std::endl; }
    
private:
    int _identifier;
    std::string _data;
    
    UpdateEvent(const UpdateEvent &) = delete;
    UpdateEvent & operator=(const UpdateEvent &) = delete;
 
public: //comment when factory used
    explicit UpdateEvent(int identifier,
                         std::string data) : _identifier(identifier),
                                             _data(data)
    {}
    
    friend class EventFactory;
    friend std::ostream & operator<<(std::ostream &out, const UpdateEvent &updateEvent);
};


std::ostream & operator<<(std::ostream &out, const UpdateEvent &updateEvent)
{
    return std::cout << "[identifier:" << updateEvent._identifier << "|data:" << updateEvent._data << "]";
}


#endif /* UpdateEvent_h */
