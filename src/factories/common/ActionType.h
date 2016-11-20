
#ifndef ActionType_h
#define ActionType_h


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


#endif /* ActionType_h */
