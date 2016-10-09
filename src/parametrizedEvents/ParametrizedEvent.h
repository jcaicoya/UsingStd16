//
//  ParametrizedEvent.h
//  UsingStd16
//


#ifndef ParametrizedEvent_h
#define ParametrizedEvent_h

#include "ParametrizedEventType.h"



template <enum ParametrizedEventType>
class ParametrizedEvent
{
public:
    void execute() { std::cout << "Error: type unkown" << std::endl; }
};


template <>
class ParametrizedEvent<ParametrizedEventType::Creation>
{
public:
    void execute() { std::cout << "CreationEvent::execute() - " << _data << std::endl; }
    
private:
    int _data;
    
public:
    ParametrizedEvent(int messageData) : _data(messageData) {}
};


template <>
class ParametrizedEvent<ParametrizedEventType::Update>
{
public:
    void execute() { std::cout << "UpdateEvent::execute() - " << _data << std::endl; }
    
private:
    int _data;
    
public:
    ParametrizedEvent(int messageData) : _data(messageData) {}
};



template <>
class ParametrizedEvent<ParametrizedEventType::Erase>
{
public:
    void execute() { std::cout << "EraseEvent::execute() - " << _data << std::endl; }
    
private:
    int _data;
    
public:
    ParametrizedEvent(int messageData) : _data(messageData) {}
};



template <>
class ParametrizedEvent<ParametrizedEventType::Unknown>
{
public:
    void execute() { std::cout << "UnknownEvent::execute() - " << _data << std::endl; }
    
private:
    int _data;
    
public:
    ParametrizedEvent(int messageData) : _data(messageData) {}
};



#endif /* ParametrizedEvent_h */
