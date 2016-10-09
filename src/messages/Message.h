//
//  Message.h
//  UsingStd16
//


#ifndef Message_h
#define Message_h

#include <string>
#include <iostream>



class Message
{
public:
    explicit Message(int identifier,
                     std::string data) : _identifier(identifier), _data(data)
    {}
    
    int getIdentifier() const { return _identifier; }
    std::string getData() const { return _data; }
    
private:
    int _identifier;
    std::string _data;
};


std::ostream & operator<<(std::ostream &out, const Message &message)
{
    return out << "[identifier:" << message.getIdentifier() << "|" << message.getData() << "]";
}

#endif /* Message_h */
