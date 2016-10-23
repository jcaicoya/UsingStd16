
#ifndef MagicDataBase_h
#define MagicDataBase_h


#include "MagicDataBaseImpl.h"

#include <memory>



template <typename DataType>
class MagicDataBase final
{
public:
    
    //MagicDataBase() : _impl(make_unique<MagicDataBaseImpl<DataType>>()) {}
    MagicDataBase() : _impl(new MagicDataBaseImpl<DataType>) {}
    MagicDataBase(const MagicDataBase &) = delete;
    MagicDataBase & operator=(const MagicDataBase &) = delete;
    
    void insert(DataType newData) {_impl->insert(newData);}
    void erase(DataType oldData) {_impl->erase(oldData);}
    void update(DataType oldData, DataType newData) {_impl->update(oldData, newData);}
    void clear() {_impl->clear();}
    bool empty() const {return _impl->empty();}
    std::size_t size() const {return _impl->size();}
    bool contains(DataType data) const {return _impl->contains(data);}
    
    using const_iterator = typename MagicDataBaseImpl<DataType>::const_iterator;
    const_iterator cbegin() const {return _impl->cbegin();}
    const_iterator cend() const {return _impl->cend();}
    
private:
    std::unique_ptr<MagicDataBaseImpl<DataType>> _impl;
};



#endif /* MagicDataBase_h */
