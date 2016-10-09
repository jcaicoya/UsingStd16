//
//  Message.h
//  UsingStd16
//
//  Created by Tweak on 25/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef Message_h
#define Message_h

#include <queue>


class Message
{
public:
    explicit Message(int data) : _data(data)
    {}
    
    int getData() const { return _data; }
    
private:
    int _data;
};


#endif /* Message_h */
