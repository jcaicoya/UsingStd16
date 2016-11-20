

#ifndef templateExamples_h
#define templateExamples_h

#include <utils/DataBase.h>

#include <sstream>


namespace templateExamples
{

// Generic data base
//
template <typename DataType,
          typename DataBase>
bool foo1(DataBase &dataBase,
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
    
    
// DataBase of DataType
//
template <typename DataType>
bool foo2(DataBase<DataType> &dataBase,
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
          ParameterType  data);

    
// Partial specialisation
//
template <typename ParameterType>
bool foo4(DataBase<std::string> &dataBase,
          ParameterType parameter)
{
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
bool foo4(DataBase<std::string> &dataBase,
          std::string data)
{
    if(true == dataBase.contains(data)) { return true; }
    std::size_t size = dataBase.size();
    dataBase.insert(data);
    return dataBase.size() == size + 1;
}




    


} // end namespace templateExamples

#endif /* templateExamples_h */
