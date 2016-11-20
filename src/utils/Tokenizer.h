
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



#endif /* Tokenizer_h */
