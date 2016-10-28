//
//  hierarchyStyleProcessMessage.h
//  UsingStd16
//
//  Created by Tweak on 28/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef hierarchyStyleProcessMessage_h
#define hierarchyStyleProcessMessage_h

#include <magicDataBase/MagicDataBase.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <iostream>

namespace processMessageImplementations
{

class ActionInterface
{
public:
    virtual void execute(DataType data) = 0;
};



class CreateAction : public ActionInterface
{
public:
    CreateAction(DataBase &dataBase) : _dataBase(dataBase) {}
    
    void execute(DataType data) { _dataBase.insert(data); }
    
private:
    DataBase &_dataBase;
};


class EraseAction : public ActionInterface
{
public:
    EraseAction(DataBase &dataBase) : _dataBase(dataBase) {}
    
    void execute(DataType data) { _dataBase.erase(data); }
    
private:
    DataBase &_dataBase;
};


class UnknownAction : public ActionInterface
{
public:
    UnknownAction() {}
    
    void execute(DataType data) { std::cout << "operation unknown" << std::endl; }
    
};


enum class ActionType { Creation, Erase, Unknown };

ActionType charToActionType(char c)
{
    ActionType actionType = ActionType::Unknown;
    if(c == 'C')
    {
        actionType = ActionType::Creation;
    }
    else if(c == 'E')
    {
        actionType = ActionType::Erase;
    }
    
    return actionType;
}


using InputData = std::tuple<int, ActionType, DataType>;

boost::optional<InputData> splitMessage(const char *message)
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




class ActionFactory
{
public:
    
    ActionFactory(DataBase &dataBase) : _dataBase(dataBase) {}
    
    std::shared_ptr<ActionInterface> build(ActionType actionType)
    {
        std::shared_ptr<ActionInterface> action;
        switch(actionType)
        {
            case ActionType::Creation:
                action = std::make_shared<CreateAction>(_dataBase);
                break;
            case ActionType::Erase:
                action = std::make_shared<EraseAction>(_dataBase);
                break;
            default:
                action = std::make_shared<UnknownAction>();
        }
        return action;
    }
    
private:
    DataBase &_dataBase;
};




void hierarchyStyle(const char *message,
                    DataBase &dataBase)
{
    auto optionaInputData = splitMessage(message);
    if(!optionaInputData)
    {
        return;
    }
    
    auto inputData = optionaInputData.get();
    auto actionType = std::get<1>(inputData);
    auto data = std::get<2>(inputData);
    
    ActionFactory actionFactory(dataBase);
    auto actionPtr = actionFactory.build(actionType);
    
    actionPtr->execute(data);
}

    
} // end namespace

#endif /* hierarchyStyleProcessMessage_h */
