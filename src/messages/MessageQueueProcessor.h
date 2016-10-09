//
//  MessageQueueProcessor.h
//  UsingStd16
//
//  Created by Tweak on 25/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef MessageQueueProcessor_h
#define MessageQueueProcessor_h

#include "MessageQueue.h"
#include "Message.h"


class MessageQueueProcessor
{
public:
    MessageQueueProcessor() : _messageQueue(),
                              _processMessageImpl(nullptr)
    {}
    
    void setProcessMessageFoo(void (*foo)(Message))
    {
        _processMessageImpl = foo;
    }
    
    void addMessageQueue(MessageQueue messageQueue)
    {
        _messageQueue = messageQueue;
    }
    
    void run()
    {
        while(false == _messageQueue.empty())
        {
            Message currentMessage = _messageQueue.front();
            _messageQueue.pop();
            processMessage(currentMessage);
        }
    }
    
private:
    void processMessage(Message message)
    {
        _processMessageImpl(message);
    }
    
    MessageQueue _messageQueue;
    void (*_processMessageImpl)(Message);
};


#endif /* MessageQueueProcessor_h */
