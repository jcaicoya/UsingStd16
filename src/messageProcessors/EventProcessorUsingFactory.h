//
//  EventProcessorUsingFactory-h.h
//  UsingStd16
//
//  Created by Tweak on 27/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef EventProcessorUsingFactory_h
#define EventProcessorUsingFactory_h

#include "../messages/Message.h"
#include "../events/EventFactory.h"


void eventProcessorUsingFactoryFoo(Message message)
{
    int messageData = message.getData();
    
    std::shared_ptr<EventItf> event = EventFactory::Build(messageData);
    
    event->execute();
}

#endif /* EventProcessorUsingFactory_h */
