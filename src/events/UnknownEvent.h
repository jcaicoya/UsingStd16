//
//  UnknonwnEvent.h
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef UnknonwnEvent_h
#define UnknonwnEvent_h

#include <iostream>

class EventFactory;


class UnknonwnEvent: public EventItf
{
public:
    
    void execute() { std::cout << "UnknonwnEvent::execute() - " << _messageId << std::endl; }

private:
    int _messageId;
    
    UnknonwnEvent(const UnknonwnEvent &) = delete;
    UnknonwnEvent & operator=(const UnknonwnEvent &) = delete;

public: //comment when factory used
    explicit UnknonwnEvent(int messageId) : _messageId(messageId) {}
    
    friend class EventFactory;
};


#endif /* UnknonwnEvent_h */
