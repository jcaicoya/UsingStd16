//
//  UpdateEvent.h
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef UpdateEvent_h
#define UpdateEvent_h

#include <iostream>


class EventFactory;


class UpdateEvent: public EventItf
{
public:
    
    void execute() { std::cout << "UpdateEvent::execute() - " << _data << std::endl; }
    
private:
    
    int _data;
    
    UpdateEvent(const UpdateEvent &) = delete;
    UpdateEvent & operator=(const UpdateEvent &) = delete;
 
public: //comment when factory used
    explicit UpdateEvent(int value) : _data(value) {}
    
    friend class EventFactory;
};

#endif /* UpdateEvent_h */
