//
//  UnknonwnEvent.h
//  UsingStd16
//


#ifndef UnknonwnEvent_h
#define UnknonwnEvent_h

#include "EventItf.h"

#include <iostream>
#include <string>



class EventFactory;


class UnknonwnEvent: public EventItf
{
public:
    
    void execute() { std::cout << "UnknonwnEvent::execute() - " << *this << std::endl; }

private:
    int _identifier;
    std::string _data;
        
    UnknonwnEvent(const UnknonwnEvent &) = delete;
    UnknonwnEvent & operator=(const UnknonwnEvent &) = delete;

public: //comment when factory used
    explicit UnknonwnEvent(int identifier,
                           std::string data) : _identifier(identifier),
                                               _data(data)
    {}
    
    friend class EventFactory;
    friend std::ostream& operator<<(std::ostream &out, const UnknonwnEvent &unknownEvent);
};


std::ostream & operator<<(std::ostream &out, const UnknonwnEvent &unknownEvent)
{
    return std::cout << "[identifier:" << unknownEvent._identifier << "|data:" << unknownEvent._data << "]";
}

#endif /* UnknonwnEvent_h */
