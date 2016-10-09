//
//  EventFactory.h
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef EventFactory_h
#define EventFactory_h


#include "EventItf.h"
#include "CreationEvent.h"
#include "UpdateEvent.h"
#include "EraseEvent.h"
#include "UnknownEvent.h"



enum class EventType
{
    Creation, Update, Erase, Unknown
};



EventType myClassifier(int message)
{
    EventType EventType = EventType::Unknown;
    
    if(message == 1)
    {
        EventType = EventType::Creation;
    }
    else if(message == 2)
    {
        EventType = EventType::Update;
    }
    else if(message == 3)
    {
        EventType = EventType::Erase;
    }
    
    return EventType;
}



class EventFactory
{
public:
    
    static std::shared_ptr<EventItf> Build(int messageData)
    {
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
        return event;
    }
    
    
    
    static std::shared_ptr<EventItf> Build(int EventId,
                                           EventType (*classifier)(int))
    {
        auto EventType = classifier(EventId);
        std::shared_ptr<EventItf> resultEvent;
        
        if(EventType == EventType::Creation)
        {
            resultEvent = std::make_shared<CreationEvent>(EventId);
        }
        else if(EventType == EventType::Update)
        {
            resultEvent = std::make_shared<UpdateEvent>(EventId);
        }
        else if(EventType == EventType::Erase)
        {
            resultEvent = std::make_shared<EraseEvent>(EventId);
        }
        else
        {
            resultEvent = std::make_shared<UnknonwnEvent>(EventId);
        }
    
    
        return resultEvent;
    }
};


//TODO: templatizar el parámetro función

#endif /* EventFactory_h */
