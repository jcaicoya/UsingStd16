//
//  main.cpp
//  UsingStd16
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
    
    
    std::cout << "1. C style processing:" << std::endl;
    messageQueueProcessor.setProcessMessageFoo(oldStyleProcessorFoo);
    messageQueueProcessor.addMessageQueue(messageQueue);
    messageQueueProcessor.run();
    
    
    std::cout << "2. OOP style processing:" << std::endl;
    messageQueueProcessor.setProcessMessageFoo(eventProcessorFoo);
    messageQueueProcessor.addMessageQueue(messageQueue);
    messageQueueProcessor.run();

    
    std::cout << "3. With factory pattern processing:" << std::endl;
    messageQueueProcessor.setProcessMessageFoo(eventProcessorUsingFactoryFoo);
    messageQueueProcessor.addMessageQueue(messageQueue);
    messageQueueProcessor.run();

    
    std::cout << "4. Templatized processing:" << std::endl;
    messageQueueProcessor.setProcessMessageFoo(parametrizedEventProcessorFoo);
    messageQueueProcessor.addMessageQueue(messageQueue);
    messageQueueProcessor.run();
    
    
    return 0;
}
