
#include "actions.h"
#include "hierarchyFactory.h"

#include <factories/common/createMessages.h>

#include <utils/DataBase.h>

#include <iostream>



using Factory = FactoryWithRegister<ActionType,
                                    ActionInterface,
                                    StringDataBase &>;

void processMessage(const std::string &message,
                    StringDataBase &dataBase,
                    Factory &factory)
{
    std::cout << "Processing message: " << message << std::endl;
    auto optionaInputData = splitMessage(message);
    if(!optionaInputData)
    {
        return;
    }
    
    auto inputData = optionaInputData.get();
    auto actionType = std::get<1>(inputData);
    auto data = std::get<2>(inputData);
    
    auto actionPtr = factory.createObject(actionType,
                                          dataBase);
    actionPtr->execute(data);
}



int main(int argc, const char * argv[])
{
    StringDataBase dataBase;
    
    Factory actionFactory;
    
    actionFactory.registerFoo(ActionType::Creation,
                              fooCreateAction);
    
    actionFactory.registerFoo(ActionType::Erase,
                              fooEraseAction);
    
    actionFactory.registerFoo(ActionType::Unknown,
                              fooUnknownAction);
    
    auto messages = createMessages();
    while(!messages.empty())
    {
        auto message = messages.front();
        messages.pop_front();
        processMessage(message,
                       dataBase,
                       actionFactory);
    }
    return 0;
}
