//
//  EventProcessor.h
//  UsingStd16
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
    int messageIdentifier = message.getIdentifier();
    std::string messageData = message.getData();
    
    std::shared_ptr<EventItf> event = std::make_shared<UnknonwnEvent>(messageIdentifier, messageData);;
    
    if(false == messageData.empty())
    {
        char firstLetter = *messageData.begin();
        if(firstLetter == 'C')
        {
            event = std::make_shared<CreationEvent>(messageIdentifier, messageData);
        }
        else if(firstLetter == 'U')
        {
            event = std::make_shared<UpdateEvent>(messageIdentifier, messageData);
        }
        else if(firstLetter == 'E')
        {
            event = std::make_shared<EraseEvent>(messageIdentifier, messageData);
        }
    }

    event->execute();
}

#endif /* EventProcessor_h */
