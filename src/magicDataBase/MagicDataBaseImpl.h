
#ifndef MagicDataBaseImpl_h
#define MagicDataBaseImpl_h


#include <vector>
#include <algorithm>


template <typename Data>
class MagicDataBaseImpl final
{
public:
    MagicDataBaseImpl();
    MagicDataBaseImpl(const MagicDataBaseImpl<Data> &) = delete;
    MagicDataBaseImpl<Data> & operator=(const MagicDataBaseImpl<Data> &) = delete;
    
    void insert(Data newData);
    void erase(Data oldData);
    void update(Data oldData, Data newData);
    void clear();
    bool empty() const;
    std::size_t size() const;
    bool contains(Data data) const;

private:
    using StorageType = std::vector<Data>;
    
public:
    using const_iterator = typename StorageType::const_iterator;
    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    StorageType _storage;
};




template <typename Data>
MagicDataBaseImpl<Data>::MagicDataBaseImpl() : _storage()
{}


template <typename Data>
void MagicDataBaseImpl<Data>::insert(Data newData)
{
    if(std::find(_storage.cbegin(), _storage.cend(), newData) == _storage.cend())
    {
       _storage.push_back(newData);
    }
}


template <typename Data>
void MagicDataBaseImpl<Data>::erase(Data oldData)
{
    const_iterator position = std::find(_storage.cbegin(), _storage.cend(), oldData);
    if(position != _storage.cend())
    {
       _storage.erase(position);
    }
}


template <typename Data>
void MagicDataBaseImpl<Data>::update(Data oldData, Data newData)
{
    typename StorageType::iterator position = std::find(_storage.begin(), _storage.end(), oldData);
    if(position != _storage.end())
    {
        *position = newData;
    }
}


template <typename Data>
void MagicDataBaseImpl<Data>::clear()
{
    _storage.clear();
}


template <typename Data>
bool MagicDataBaseImpl<Data>::empty() const
{
    return _storage.empty();
}


template <typename Data>
std::size_t MagicDataBaseImpl<Data>::size() const
{
    return _storage.size();
}


template <typename Data>
bool MagicDataBaseImpl<Data>::contains(Data data) const
{
    return std::find(_storage.cbegin(), _storage.cend(), data) != _storage.cend();

}


template <typename Data>
typename MagicDataBaseImpl<Data>::const_iterator MagicDataBaseImpl<Data>::cbegin() const
{
    return _storage.cbegin();
}


template <typename Data>
typename MagicDataBaseImpl<Data>::const_iterator MagicDataBaseImpl<Data>::cend() const
{
    return _storage.cend();
}



#endif /* MagicDataBaseImpl_h */
