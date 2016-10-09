//
//  MessageQueue.h
//  UsingStd16
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
        _queue.push(Message(1, "C # Stormtrooper # FN-2186"));
        _queue.push(Message(2, "M # Stormtrooper # FN-2186 # FN-2187"));
        _queue.push(Message(3, "B # Stormtrooper FN-2187 betrayer"));
        _queue.push(Message(4, "E # Stormtrooper FN-2187"));
    }
    
    bool empty() const { return _queue.empty(); }
    Message front() const { return _queue.front(); }
    void pop() { _queue.pop(); }
    
private:
    std::queue<Message> _queue;
};

#endif /* MessageQueue_h */
