//
//  OldStyleProcessor.h
//  UsingStd16
//
//  Created by Tweak on 25/9/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef OldStyleProcessor_h
#define OldStyleProcessor_h

#include "messages/Message.h"

#include <iostream>


void oldStyleProcessorFoo(Message message)
{
    int messageData = message.getData();
    
    if(messageData == 1)
    {
        std::cout << "Managing message with data: 1 -> creation" << std::endl;
    }
    else if(messageData == 2)
    {
        std::cout << "Managing message with data: 2 -> update" << std::endl;
    }
    else if(messageData == 3)
    {
        std::cout << "Managing message with data: 3 -> erase" << std::endl;
    }
    else
    {
        std::cout << "Managing message with data: " << messageData << " -> unknonwn" << std::endl;
    }
}

#endif /* OldStyleProcessor_h */
