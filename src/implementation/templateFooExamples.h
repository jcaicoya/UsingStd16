

#ifndef templateExamples_h
#define templateExamples_h

#include <utils/DataBase.h>

#include <sstream>
#include <iostream>


namespace templateExamples
{



// Specialization over a generic container of particular type
//

template <typename DataBaseValueType,
          typename ParameterType>
bool foo(DataBase<DataBaseValueType> &dataBase,
         ParameterType parameter)
{
    std::cout << "Generic specialisation" << std::endl;
    DataBaseValueType dataToInsert(parameter);
    if(true == dataBase.contains(dataToInsert)) { return true; }
    std::size_t size = dataBase.size();
    dataBase.insert(dataToInsert);
    return dataBase.size() == size + 1;

}

    
// Partial specialisation
//
template <typename ParameterType>
bool foo(DataBase<std::string> &dataBase,
         ParameterType parameter)
{
    std::cout << "Partial specialisation" << std::endl;
    
    std::stringstream ss;
    ss << parameter;
    std::string data = ss.str();
    
    if(true == dataBase.contains(data)) { return true; }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}
    

// Total specialization
//
template <>
bool foo(DataBase<std::string> &dataBase,
         std::string data)
{
    std::cout << "Total specialisation" << std::endl;
    if(true == dataBase.contains(data)) { return true; }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}


} // end namespace templateExamples

#endif /* templateExamples_h */
