

#include "templateFooExamples.h"
#include "templateTypeExamples.h"
#include "variadicTemplates.h"

#include <utils/DataBase.h>

#include <iostream>



template <typename ...Args>
void printIsPalindrome(Args... args)
{
    std::tuple<Args...> argsTuple(args...);
    std::cout << argsTuple << " is";
    if(false == isPalindrome(argsTuple))
    {
        std::cout << " not";
    }
    std::cout << " a palindrome"<< std::endl;
}



int main(int argc, const char * argv[])
{
    std::cout << std::boolalpha;
    
    
    
    DataBase<std::string> stringDB;
    std::string st = "FN-2187";
    
    DataBase<double> doubleDB;
    double zero = 0.0;
    
    int prettyGirl = 15;
    
    /*
    bool result1 = templateExamples::foo<std::string,
                                        DataBase<std::string>,
                                        std::string>(stringDB, st);
     */
    
    bool result1 = templateExamples::foo<double, int>(doubleDB, prettyGirl);
    bool result2 = templateExamples::foo<double>(stringDB, zero);
    bool result3 = templateExamples::foo<std::string>(stringDB, st);
    


    /*
    DataBase<double> doubleDB;
    int prettyGirl = 15;
    bool result3 = templateExamples::foo<double,
                                   DataBase<std::string>,
                                   int>(doubleDB, prettyGirl);
     */
    
    
    std::cout << parametersToString(1, "two", 3.0, 4) << std::endl;
    std::cout << parametersToStringReverse(1, "two", 3.0, 4) << std::endl;
    
    printIsPalindrome(1, 'A', 15.1, 'A', 1);
    printIsPalindrome(1, 'A', 15.1, 'B', 1);

    printIsPalindrome(1);
    printIsPalindrome();
    //printIsPalindrome(1, 'A', 15.1, 15.1, 'A', 1);
    //printIsPalindrome(1, 'A', 15.1, 16.1, 'A', 1);
    
    
    
    using integer = int;
    templateExamples::CompileTimeEvaluator<sizeof(integer) == sizeof(int)>();
    //templateExamples::CompileTimeEvaluator<sizeof(integer) == sizeof(char)>();

    return 0;
}
