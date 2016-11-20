
#ifndef DataBase_h
#define DataBase_h

#include <vector>

template <typename DataType,
          typename Container = std::vector<DataType>>
class DataBase final
{
public:
    
    DataBase();
    DataBase(const DataBase &) = delete;
    DataBase(DataBase &&) = default;
    DataBase & operator=(const DataBase &) = delete;
    DataBase & operator=(DataBase &&) = default;
    
    void insert(DataType newData);
    void erase(DataType oldData);
   
    std::size_t size() const;
    bool contains(DataType data) const;
    
private:
    Container _container;
};


#include "DataBaseImpl.h"


#endif /* DataBase_h */
