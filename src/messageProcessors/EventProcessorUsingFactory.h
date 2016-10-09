//
//  EventProcessorUsingFactory-h.h
//  UsingStd16
//


#ifndef EventProcessorUsingFactory_h
#define EventProcessorUsingFactory_h

#include "messages/Message.h"
#include "../events/EventFactory.h"


void eventProcessorUsingFactoryFoo(Message message)
{
    int messageIdentifier = message.getIdentifier();
    std::string messageData = message.getData();
    
    std::shared_ptr<EventItf> event = EventFactory::Build(messageIdentifier, messageData);
    
    event->execute();
}

#endif /* EventProcessorUsingFactory_h */
