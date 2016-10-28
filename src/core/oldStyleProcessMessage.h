
#ifndef oldStyleProcessMessage_h
#define oldStyleProcessMessage_h

#include <utils/Tokenizer.h>

//#include <boost/lexical_cast.hpp>

#include <iostream>

#include <magicDataBase/MagicDataBase.h>


namespace processMessageImplementations
{
    
    
void oldStyle(const char *message,
              DataBase &dataBase)
{
    auto tokens = Tokenizer::Split(message, '#');
    if(tokens.size() != 3)
    {
        std::cout << "wrong number of parameters in " << message << std::endl;
        return;
    }
    
    //Warning: unused vable id
    //int id = boost::lexical_cast<int>(tokens[0]);
    Tokenizer::Token operationStr = tokens[1];
    if(operationStr.size() != 1)
    {
        std::cout << "operationStr unknown " << operationStr << std::endl;
        return;
    }
    DataType data = tokens[2];
    
    char operation = operationStr.front();
    switch(operation)
    {
        case 'C': dataBase.insert(data);
            break;
        case 'E': dataBase.erase(data);
            break;
        default:
            std::cout << "operation unknown " << operation << std::endl;
    }
}

    
} // end namespace


#endif /* oldStyleProcessMessage_h */
