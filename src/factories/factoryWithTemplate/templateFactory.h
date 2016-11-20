
#ifndef ProcessMessage_h
#define ProcessMessage_h


#include <utils/DataBase.h>

#include <iostream>


using StringDataBase = DataBase<std::string>;


    
class CreateAction
{
public:
    CreateAction(DataBase &dataBase) : _dataBase(dataBase) {}
        
    void execute(DataType data) { _dataBase.insert(data); }
        
private:
    DataBase &_dataBase;
};


    
class EraseAction
{
public:
    EraseAction(DataBase &dataBase) : _dataBase(dataBase) {}
        
    void execute(DataType data) { _dataBase.erase(data); }
        
private:
    DataBase &_dataBase;
};
    


class UnknownAction
{
public:
    UnknownAction() {}
        
    void execute(DataType data) { std::cout << "operation unknown" << std::endl; }
};
    
    



class ActionFactory
{
public:
    template <typename Action,
              ActionType actionType>
    static Action Build(DataBase &dataBase);
};



template <>
CreateAction ActionFactory::Build<CreateAction,
                                 ActionType::Creation>(DataBase &dataBase)
{
    return CreateAction(dataBase);
}
    
template <>
EraseAction ActionFactory::Build<EraseAction,
                                ActionType::Erase>(DataBase &dataBase)
{
    return EraseAction(dataBase);
}
    
    
template <>
UnknownAction ActionFactory::Build<UnknownAction,
                                   ActionType::Unknown>(DataBase &/*dataBase*/)
{
    return UnknownAction();
}

    
void procesMessage(const char *message,
                   DataBase &dataBase)
{
    auto optionaInputData = splitMessage(message);
    if(!optionaInputData)
    {
        return;
    }
    auto inputData = optionaInputData.get();
    
    auto id = std::get<0>(inputData);
    auto actionType = std::get<1>(inputData);
    auto data = std::get<2>(inputData);
    
}


#endif /* ProcessMessage_h */
