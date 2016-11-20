
#ifndef DataBaseImpl_h
#define DataBaseImpl_h


#include <vector>
#include <algorithm>


template <typename Data,
          typename Container = std::vector<Data> >
class DataBaseImpl final
{
public:
    DataBaseImpl();
    DataBaseImpl(const DataBaseImpl<Data> &) = delete;
    DataBaseImpl<Data> & operator=(const DataBaseImpl<Data> &) = delete;
    
    void insert(Data newData);
    void erase(Data oldData);
    
    std::size_t size() const;
    bool contains(Data data) const;

private:
    Container _storage;
};




template <typename Data,
          typename Container>
DataBaseImpl<Data, Container>::DataBaseImpl() : _storage()
{}


template <typename Data,
          typename Container>
void DataBaseImpl<Data, Container>::insert(Data newData)
{
    if(std::find(_storage.cbegin(), _storage.cend(), newData) == _storage.cend())
    {
       _storage.push_back(newData);
    }
}


template <typename Data,
          typename Container>
void DataBaseImpl<Data, Container>::erase(Data oldData)
{
    auto position = std::find(_storage.cbegin(), _storage.cend(), oldData);
    if(position != _storage.cend())
    {
       _storage.erase(position);
    }
}


template <typename Data,
          typename Container>
std::size_t DataBaseImpl<Data, Container>::size() const
{
    return _storage.size();
}


template <typename Data,
          typename Container>
bool DataBaseImpl<Data, Container>::contains(Data data) const
{
    return std::find(_storage.cbegin(), _storage.cend(), data) != _storage.cend();

}




#endif /* DataBaseImpl_h */
