//
//  processMessage.h
//  UsingStd16
//
//  Created by Tweak on 23/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef processMessage_h
#define processMessage_h


#include "processMessageImplementations.h"


using FooType = void (*)(const char *,
                         MagicDataBase<std::string> &);


void processMessageImpl(const char *message,
                        MagicDataBase<std::string> &dataBase,
                        FooType foo)
{
    foo(message,
        dataBase);
}


void processMessage(const char *message,
                    MagicDataBase<std::string> &dataBase)
{
    processMessageImpl(message,
                       dataBase,
                       processMessageImplementations::oldStyle);
}



#endif /* processMessage_h */
