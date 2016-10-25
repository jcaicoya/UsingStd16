//
//  Tokenizer.h
//  UsingStd16
//
//  Created by Tweak on 25/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef Tokenizer_h
#define Tokenizer_h


#include <string>
#include <vector>


class Tokenizer
{
public:
    using Token = std::string;
    using Tokens = std::vector<Token>;
    
    static Tokens Split(const std::string &str,
                        char separator,
                        bool trim = true);
    
private:
    static std::string WithoutSpaces(const std::string &str);
};



Tokenizer::Tokens Tokenizer::Split(const std::string &str,
                                   char separator,
                                   bool withoutSpaces)
{
    std::string  newStr = str;
    if(true == withoutSpaces)
    {
        newStr = WithoutSpaces(str);
    }
    
    Tokens tokens;
    if(newStr.empty())
    {
        return tokens;
    }
    
    std::size_t previous = 0;
    std::size_t pos = newStr.find(separator, previous);
    while(pos != std::string::npos)
    {
        Token token = newStr.substr(previous, pos - previous);
        if(false == token.empty())
        {
           tokens.push_back(token);
        }
        previous = pos + 1;
        pos = newStr.find(separator, previous);
    }
    
    if(previous < newStr.size())
    {
        Token token = newStr.substr(previous, newStr.size() - previous);
        if(false == token.empty())
        {
            tokens.push_back(token);
        }
    }
    
    return tokens;
}

    
std::string Tokenizer::WithoutSpaces(const std::string &str)
{
    std::string result = str;
    auto itr = std::remove_if(result.begin(),
                              result.end(),
                              [](char x){return std::isspace(x);});
    result.erase(itr,
                 result.end());
    return result;
    
}



#endif /* Tokenizer_h */
