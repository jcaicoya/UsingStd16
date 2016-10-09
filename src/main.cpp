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





/*

class Bomb {
    int x;
public:
    Bomb() : x(0) {}
    ~Bomb() { throw "boom"; }
    
    void * operator new(size_t n) throw()
    {
        printf("operator new called\n");
        return malloc(n);
    }
    
    void operator delete(void *p) throw()
    {
        printf("operator delete called\n");
        if (p != 0) free(p);
            }
};

void f() {
    Bomb myBomb;
    
    Bomb *pBomb = new Bomb();
    try {
        delete pBomb;
    } catch (...) {
        printf("caught exception\n");
    }
    throw "no boom";
}

int main(int argc, char **argv)
{
    try {
        f();
    } catch (char *message) {
        printf("f threw %s\n", message);
    }
}
 */


