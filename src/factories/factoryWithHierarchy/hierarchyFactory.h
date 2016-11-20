
#ifndef hierarchyFactory_h
#define hierarchyFactory_h

#include "actions.h"

#include <utils/DataBase.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <iostream>
#include <map>


using StringDataBase = DataBase<std::string>;

class ActionFactory
{
public:
    
    ActionFactory(StringDataBase &dataBase) : _dataBase(dataBase) {}
    
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
    StringDataBase &_dataBase;
};






template <typename KeyType,
          typename ResultType,
          typename ...Args>
class FactoryWithRegister
{
public:
    void registerFoo(KeyType key,
                     std::shared_ptr<ResultType> (*foo)(Args ...args))
    {
        _data[key] = foo;
    }
    
    std::shared_ptr<ResultType> createObject(KeyType key,
                                             Args ...args)
    {
        return _data[key](args...);
    }
    
private:
    std::map<KeyType,
              std::shared_ptr<ResultType> (*)(Args ...)> _data;
};













#endif /* hierarchyFactory_h */
