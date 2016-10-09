//
//  main.cpp
//  UsingStd16
//
//  Created by Tweak on 20/8/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#include "messages/MessageQueue.h"
#include "messages/MessageQueueProcessor.h"
#include "messageProcessors/OldStyleProcessor.h"
#include "messageProcessors/EventProcessor.h"
#include "messageProcessors/EventProcessorUsingFactory.h"
#include "messageProcessors/ParametrizedEventProcessor.h"



int main(int argc, const char * argv[])
{
    
    MessageQueue messageQueue;
    messageQueue.load();
    
    MessageQueueProcessor messageQueueProcessor;
    //1. messageQueueProcessor.setProcessMessageFoo(oldStyleProcessorFoo);
    //2. messageQueueProcessor.setProcessMessageFoo(eventProcessorFoo);
    //3. messageQueueProcessor.setProcessMessageFoo(eventProcessorUsingFactoryFoo);
    messageQueueProcessor.setProcessMessageFoo(eventProcessorUsingFactoryFoo);
    messageQueueProcessor.setProcessMessageFoo(parametrizedEventProcessorFoo);
    messageQueueProcessor.addMessageQueue(messageQueue);
    messageQueueProcessor.run();
    
    return 0;
}
