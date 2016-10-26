//
//  processMessageImplementations.h
//  UsingStd16
//
//  Created by Tweak on 23/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef processMessageImplementations_h
#define processMessageImplementations_h


#include <utils/Tokenizer.h>

#include <boost/lexical_cast.hpp>

#include <iostream>



namespace processMessageImplementations
{


void oldStyle(const char *message,
              MagicDataBase<std::string> &dataBase)
{
    auto tokens = Tokenizer::Split(message, '#');
    if(tokens.size() != 3)
    {
        std::cout << "oldStyle: wrong number of parameters in " << message << std::endl;
        return;
    }
    
    //int id = boost::lexical_cast<int>(tokens[0]);
    std::string operationStr = tokens[1];
    if(operationStr.size() != 1)
    {
        std::cout << "oldStyle: operationStr unknown " << operationStr << std::endl;
        return;
    }
    std::string data = tokens[2];
    
    char operation = operationStr.front();
    switch(operation)
    {
        case 'C': dataBase.insert(data);
            break;
        case 'E': dataBase.erase(data);
            break;
        default:
            std::cout << "oldStile: operation unknown " << operation << std::endl;
    }
}
    

void hierarchy(const char *message,
               MagicDataBase<std::string> &dataBase)
{
}
    

void templatized(const char *message,
                 MagicDataBase<std::string> &dataBase)
{
        
}
    
    
    
    
} // end namespace processMessageImplementations


#endif /* processMessageImplementations_h */
