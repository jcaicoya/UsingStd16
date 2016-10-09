//
//  ParametrizedEventProcessor.h
//  UsingStd16
//
//  Created by Tweak on 27/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef ParametrizedEventProcessor_h
#define ParametrizedEventProcessor_h

#include "message/Message.h"
#include "parametrizedEvents/ParametrizedEvent.h"


void parametrizedEventProcessorFoo(Message message)
{
    int messageData = message.getData();
    
    ParametrizedEventType eventType = ParametrizedEventType::Unknown;
    if(messageData == 1)
    {
        eventType = ParametrizedEventType::Creation;
    }
    else if(messageData == 2)
    {
        eventType = ParametrizedEventType::Update;
    }
    else if(messageData == 3)
    {
        eventType = ParametrizedEventType::Erase;
    }
    
    //ParametrizedEvent<eventType> parametrizedEvent;
    //parametrizedEvent.execute();
}


#endif /* ParametrizedEventProcessor_h */
