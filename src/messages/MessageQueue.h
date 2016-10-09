//
//  MessageQueue.h
//  UsingStd16
//
//  Created by Tweak on 25/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef MessageQueue_h
#define MessageQueue_h


#include "Message.h"

#include <queue>



class MessageQueue
{
public:
    MessageQueue() : _queue()
    {}
    
    void load()
    {
        for(int ii=1; ii<=10; ii++)
        {
            _queue.push(Message(ii % 4));
        }
    }
    
    bool empty() const { return _queue.empty(); }
    Message front() const { return _queue.front(); }
    void pop() { _queue.pop(); }
    
private:
    std::queue<Message> _queue;
};

#endif /* MessageQueue_h */
