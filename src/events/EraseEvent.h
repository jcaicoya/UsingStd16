//
//  EraseEvent.h
//  UsingStd16
//


#ifndef EraseEvent_h
#define EraseEvent_h

#include "EventItf.h"

#include <iostream>
#include <string>

class EventFactory;


class EraseEvent: public EventItf
{
public:
    
    void execute() { std::cout << "EraseEvent::execute() - " << *this << std::endl; }

private:
    int _identifier;
    std::string _data;
    
    EraseEvent(const EraseEvent &) = delete;
    EraseEvent & operator=(const EraseEvent &) = delete;
    
public: //comment when factory used
    explicit EraseEvent(int identifier,
                        std::string data) : _identifier(identifier),
                                            _data(data)
    {}
    
    friend class EventFactory;
    friend std::ostream & operator<<(std::ostream &out, const EraseEvent &unknownEvent);
};


std::ostream & operator<<(std::ostream &out, const EraseEvent &eraseEvent)
{
    return std::cout << "[identifier:" << eraseEvent._identifier << "|data:" << eraseEvent._data << "]";
}


#endif /* EraseEvent_h */
