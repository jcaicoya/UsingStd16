//
//  EventProcessor.h
//  UsingStd16
//
//  Created by Tweak on 27/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef EventProcessor_h
#define EventProcessor_h

#include "messages/Message.h"

#include "events/EventItf.h"
#include "events/CreationEvent.h"
#include "events/UpdateEvent.h"
#include "events/EraseEvent.h"
#include "events/UnknownEvent.h"



void eventProcessorFoo(Message message)
{
    int messageData = message.getData();
    
    std::shared_ptr<EventItf> event = nullptr;
    if(messageData == 1)
    {
        event = std::make_shared<CreationEvent>(messageData);
    }
    else if(messageData == 2)
    {
        event = std::make_shared<UpdateEvent>(messageData);
    }
    else if(messageData == 3)
    {
        event = std::make_shared<EraseEvent>(messageData);
    }
    else
    {
        event = std::make_shared<UnknonwnEvent>(messageData);
    }
    
    event->execute();
}

#endif /* EventProcessor_h */
