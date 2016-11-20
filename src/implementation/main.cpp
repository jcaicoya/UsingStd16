

#include "templateFooExamples.h"
#include "templateTypeExamples.h"
#include "variadicTemplates.h"

#include <utils/DataBase.h>

#include <iostream>



template <typename ...Args>
void printPalindrome(Args... args)
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
    DataBase<std::string> db;
    DataBase<int> otherDB;
    std::string st = "FN-2187";
    
    bool result = templateExamples::foo1(db, st);
    std::cout << "foo1: result = " << result << std::endl;
    
    //result = templateExamples::foo1(otherDB, st);
    //std::cout << "foo1: result = " << result << std::endl;
    
    result = templateExamples::foo2(db, st);
    std::cout << "foo2: result = " << result << std::endl;
    
    //result = templateExamples::foo2(otherDB, st);
    //std::cout << "foo2: result = " << result << std::endl;
    
    
    //result = templateExamples::foo3(db, st);
    //std::cout << "foo3: result = " << result << std::endl;
    
    //result = templateExamples::foo3(otherDB, st);
    //std::cout << "foo3: result = " << result << std::endl;
    
    
    std::cout << parametersToString(1, "two", 3.0, 4) << std::endl;
    std::cout << parametersToStringReverse(1, "two", 3.0, 4) << std::endl;
    //std::cout << palindrome(1, "one", "one", 1) << std::endl;
    
    printPalindrome(1, 'A', 15.1, 'A', 1);
    printPalindrome(1, 'A', 15.1, 'B', 1);

    printPalindrome(1);
    printPalindrome();
    //printPalindrome(1, 'A', 15.1, 15.1, 'A', 1);
    //printPalindrome(1, 'A', 15.1, 16.1, 'A', 1);
    
    
    
    using integer = int;
    templateExamples::CompileTimeEvaluator<sizeof(integer) == sizeof(int)>();
    //templateExamples::CompileTimeEvaluator<sizeof(integer) == sizeof(char)>();

    
    const int TypeOfAlgorithm = 1;
    std::vector<int> container;
    
    //templateExamples::Strategy::Execute(TypeOfAlgorithm, container);
    

    
    
    return 0;
}
