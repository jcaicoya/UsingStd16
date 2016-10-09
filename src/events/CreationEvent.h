//
//  CreationEvent.h
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef CreationEvent_h
#define CreationEvent_h

#include <iostream>

class EventFactory;


class CreationEvent: public EventItf
{
public:
    
    void execute() { std::cout << "CreationEvent::execute() - " << _data << std::endl; }

private:
    int _data;
    
    CreationEvent(const CreationEvent &) = delete;
    CreationEvent & operator=(const CreationEvent &) = delete;

public: //comment when factory used
    explicit CreationEvent(int value) : _data(value) {}
    
    friend class EventFactory;
};


#endif /* CreationEvent_h */
