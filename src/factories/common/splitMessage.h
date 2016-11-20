
#ifndef splitMessage_h
#define splitMessage_h

#include "ActionType.h"
#include <utils/Tokenizer.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <iostream>


using DataType = std::string;
using InputData = std::tuple<int, ActionType, DataType>;


boost::optional<InputData> splitMessage(const std::string &message)
{
    boost::optional<InputData> result;
    auto tokens = Tokenizer::Split(message, '#');
    if(tokens.size() != 3)
    {
        std::cout << "wrong number of parameters in " << message << std::endl;
        return result;
    }
    
    int id = boost::lexical_cast<int>(tokens[0]);
    Tokenizer::Token operationStr = tokens[1];
    if(operationStr.size() != 1)
    {
        std::cout << "operationStr unknown " << operationStr << std::endl;
        return result;
    }
    
    auto actionType = charToActionType(operationStr[0]);
    DataType data = tokens[2];
    result = InputData(id,
                       actionType,
                       data);
    return result;
}



#endif /* splitMessage_h */
