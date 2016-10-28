
#ifndef processMessage_h
#define processMessage_h


#include "oldStyleProcessMessage.h"
#include "hierarchyStyleProcessMessage.h"
#include "templateStyleProcessMessage.h"

#include <MagicDataBase/magicDataBase.h>



using FooType = void (*)(const char *,
                         DataBase &);



void processMessageImpl(const char *message,
                        DataBase &dataBase,
                        FooType foo)
{
    foo(message,
        dataBase);
}



void processMessage(const char *message,
                    DataBase &dataBase)
{
    int option = 'T';
    
    if(option == 'O')
    {
       processMessageImpl(message,
                          dataBase,
                          processMessageImplementations::oldStyle);
    }
    else if(option == 'H')
    {
       processMessageImpl(message,
                          dataBase,
                          processMessageImplementations::hierarchyStyle);
    }
    else
    {
       processMessageImpl(message,
                          dataBase,
                          processMessageImplementations::templateStyle);
    }
}



#endif /* processMessage_h */
