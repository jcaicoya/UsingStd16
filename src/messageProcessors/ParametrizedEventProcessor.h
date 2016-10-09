//
//  ParametrizedEventProcessor.h
//  UsingStd16
//


#ifndef ParametrizedEventProcessor_h
#define ParametrizedEventProcessor_h

#include "messages/Message.h"
#include "parametrizedEvents/ParametrizedEvent.h"


void parametrizedEventProcessorFoo(Message message)
{
    //int messageIdentifier = message.getIdentifier();
    std::string messageData = message.getData();
    
    ParametrizedEventType eventType = ParametrizedEventType::Unknown;
    
    if(false == messageData.empty())
    {
        char firstLetter = *messageData.begin();
        if(firstLetter == 'C')
        {
           eventType = ParametrizedEventType::Creation;
        }
        else if(firstLetter == 'U')
        {
           eventType = ParametrizedEventType::Update;
        }
        else if(firstLetter == 'E')
        {
           eventType = ParametrizedEventType::Erase;
        }
    }
    
    /*
    ParametrizedEvent<eventType> parametrizedEvent(messageIdentifier,
                                                   messageData);
    parametrizedEvent.execute();
     */
}


#endif /* ParametrizedEventProcessor_h */
