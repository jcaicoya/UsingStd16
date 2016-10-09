//
//  EraseEvent.h
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef EraseEvent_h
#define EraseEvent_h

#include <iostream>

class EventFactory;


class EraseEvent: public EventItf
{
public:
    
    void execute() { std::cout << "EraseEvent::execute() - " << _data << std::endl; }

private:
    int _data;
    
    EraseEvent(const EraseEvent &) = delete;
    EraseEvent & operator=(const EraseEvent &) = delete;
    
public: //comment when factory used
    explicit EraseEvent(int value) : _data(value) {}
    
    friend class EventFactory;
};


#endif /* EraseEvent_h */
