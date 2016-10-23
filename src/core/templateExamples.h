//
//  templateExamples.h
//  UsingStd16
//
//  Created by Tweak on 23/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef templateExamples_h
#define templateExamples_h

#include <magicDataBase/MagicDataBase.h>

#include <sstream>


namespace templateExamples
{

// Simplest case
//
template <typename DataType>
bool foo1(MagicDataBase<DataType> &dataBase,
          DataType data)
{
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}


// Generic data base
//
template <typename DataBase,
          typename DataType>
bool foo2(DataBase &dataBase,
          DataType data)
{
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}
    

// Generic data base with data dependence
//
template <typename DataType,
          template <typename> typename DataBase>
bool foo3(DataBase<DataType> &dataBase,
          DataType data)
{
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}


// TODO: review this example //
// Specialization over a generic container of particular type
//
template <typename DataBaseValueType,
          template <typename> typename DataBase,
          typename ParameterType>
bool foo4(DataBase<DataBaseValueType> &dataBase,
          ParameterType  data)
{
    return false;
}
    
// Partial specialization
//
template <typename ParameterType>
bool foo4(MagicDataBase<std::string> &dataBase,
          ParameterType parameter)
{
    std::stringstream ss;
    ss << parameter;
    std::string data = ss.str();
    
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}

// Total specialization
//
template <>
bool foo4(MagicDataBase<std::string> &dataBase,
          std::string data)
{
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}



///////////////////////////////////
// Variadic templates
//
template <typename ParameterType>
std::string parametersToString(ParameterType lastParameter)
{
    std::stringstream ss;
    ss << lastParameter;
    std::string data = ss.str();
    return data;
}
    
    
template <typename ParameterType,
          typename... ArgumentTypes>
std::string parametersToString(ParameterType currentParameter,
                               ArgumentTypes... arguments)
{
    std::stringstream ss;
    ss << currentParameter;
    std::string data = ss.str();
    return data + parametersToString(arguments...);
}
  


std::string parametersToString(std::string lastParameter)
{
    return lastParameter;
}
    
    
template <typename... ArgumentTypes>
std::string parametersToString(std::string currentParameter,
                               ArgumentTypes... arguments)
{
    return currentParameter + parametersToString(arguments...);
}
    
    
    
// TODO: variadic templates in reverse order

    
template <typename... ArgumentTypes>
bool foo5(MagicDataBase<std::string> &dataBase,
          ArgumentTypes... arguments)
{
    std::string data = parametersToString(arguments...);
    if(true == dataBase.contains(data))
    {
        return true;
    }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;

}
    


} // end namespace templateExamples

#endif /* templateExamples_h */
