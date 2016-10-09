//
//  CStyleProcessor.h
//  UsingStd16
//


#ifndef OldStyleProcessor_h
#define OldStyleProcessor_h

#include "messages/Message.h"
#include "events/CreationEvent.h"
#include "events/UpdateEvent.h"
#include "events/EraseEvent.h"
#include "events/UnknownEvent.h"

#include <iostream>


void oldStyleProcessorFoo(Message message)
{
    int messageIdentifier = message.getIdentifier();
    std::string messageData = message.getData();
    
    bool validMessage = false;
    
    if(false == messageData.empty())
    {
        char firstLetter = *messageData.begin();
        if(firstLetter == 'C')
        {
            validMessage = true;
            CreationEvent creationEvent(messageIdentifier, messageData);
            creationEvent.execute();
        }
        else if(firstLetter == 'U')
        {
            validMessage = true;
            UpdateEvent updateEvent(messageIdentifier, messageData);
            updateEvent.execute();
        }
        else if(firstLetter == 'E')
        {
            validMessage = true;
            EraseEvent eraseEvent(messageIdentifier, messageData);
            eraseEvent.execute();
        }
    }
    
    if(false == validMessage)
    {
        UnknonwnEvent unknownEvent(messageIdentifier, messageData);
        unknownEvent.execute();
    }
}

#endif /* OldStyleProcessor_h */
