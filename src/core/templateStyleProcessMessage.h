
#ifndef templateStyleProcessMessage_h
#define templateStyleProcessMessage_h


#include <magicDataBase/MagicDataBase.h>


namespace processMessageImplementations
{

template <typename Action, int actionType>
class ActionFactoryTemplatized;

/*{
 public:
 ActionFactoryTemplatized(DataBase &dataBase) : _dataBase(dataBase) {}
 
 private:
 DataBase &_dataBase;
 };
 */


/*
template <typename Action>
class ActionFactoryTemplatized<0>
{
public:
    ActionFactoryTemplatized<ActionType::Creation>(DataBase &dataBase) : _dataBase(dataBase) {}
    
    Action build() { return CreateAction(_dataBase); }
    
private:
    DataBase &_dataBase;
};
*/


void templateStyle(const char *message,
                   DataBase &dataBase)
{
    
}

} // end namespace

#endif /* templateStyleProcessMessage_h */
