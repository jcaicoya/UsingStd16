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
    

    


} // end namespace templateExamples

#endif /* templateExamples_h */
