//
//  EventFactory.h
//  UsingStd16
//


#ifndef EventFactory_h
#define EventFactory_h


#include "EventItf.h"
#include "CreationEvent.h"
#include "UpdateEvent.h"
#include "EraseEvent.h"
#include "UnknownEvent.h"



class EventFactory
{
public:
    
    static std::shared_ptr<EventItf> Build(int messageIdentifier,
                                           std::string messageData)
    {
        std::shared_ptr<EventItf> event = std::make_shared<UnknonwnEvent>(messageIdentifier, messageData);
        
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
    
        return event;
    }
};


#endif /* EventFactory_h */
