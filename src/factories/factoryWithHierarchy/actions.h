
#ifndef actions_h
#define actions_h


#include <factories/common/splitMessage.h>

#include <utils/DataBase.h>

using StringDataBase = DataBase<std::string>;

class ActionInterface
{
public:
    virtual void execute(DataType data) = 0;
};


class CreateAction : public ActionInterface
{
public:
    CreateAction(StringDataBase &dataBase) : _dataBase(dataBase) {}
    
    void execute(DataType data) { _dataBase.insert(data); }
    
private:
    StringDataBase &_dataBase;
};


class EraseAction : public ActionInterface
{
public:
    EraseAction(StringDataBase &dataBase) : _dataBase(dataBase) {}
    
    void execute(DataType data) { _dataBase.erase(data); }
    
private:
    StringDataBase &_dataBase;
};


class UnknownAction : public ActionInterface
{
public:
    UnknownAction() {}
    
    void execute(DataType /*data*/) { std::cout << "operation unknown" << std::endl; }
};




std::shared_ptr<ActionInterface> fooCreateAction(StringDataBase &dataBase)
{ return std::shared_ptr<ActionInterface>(std::make_shared<CreateAction>(dataBase)); }

std::shared_ptr<ActionInterface> fooEraseAction(StringDataBase &dataBase)
{ return std::shared_ptr<ActionInterface>(std::make_shared<EraseAction>(dataBase)); }

std::shared_ptr<ActionInterface> fooUnknownAction(StringDataBase &/*dataBase*/)
{ return std::shared_ptr<ActionInterface>(std::make_shared<UnknownAction>()); }



#endif /* actions_h */
