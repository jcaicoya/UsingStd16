
#ifndef createMessages_h
#define createMessages_h


#include <deque>

using Queue = std::deque<std::string>;

Queue createMessages()
{
    Queue queue;
    queue.push_back("1#C#FN2186");
    queue.push_back("2#C#FN2187");
    queue.push_back("3#U#FN2187");
    queue.push_back("4#E#FN2187");
    return queue;
}



#endif /* createMessages_h */
