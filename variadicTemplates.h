//
//  variadicTemplates.h
//  UsingStd16
//
//  Created by Tweak on 20/11/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef variadicTemplates_h
#define variadicTemplates_h



template <typename ParameterType>
std::string parametersToString(ParameterType lastParameter)
{
    std::stringstream ss;
    ss << lastParameter;
    return ss.str();
}


template <typename ParameterType,
          typename... ArgumentTypes>
std::string parametersToString(ParameterType currentParameter,
                               ArgumentTypes... arguments)
{
    std::stringstream ss;
    ss << currentParameter << ' ' << parametersToString(arguments...);
    return ss.str();
}



template <typename ParameterType>
std::string parametersToStringReverse(ParameterType firstParameter)
{
    std::stringstream ss;
    ss << firstParameter;
    return ss.str();
}


template <typename ParameterType,
          typename... ArgumentTypes>
std::string parametersToStringReverse(ParameterType currentParameter,
                                      ArgumentTypes... arguments)
{
    std::stringstream ss;
    ss <<  parametersToStringReverse(arguments...) << ' ' << currentParameter;
    return ss.str();
}


/*
template <typename Fisrt,
          typename... ArgumentTypes,
          typename Last>
bool isPalindrome(First first,
                  ArgementTypes... arguments,
                  Last last)
{
    // Nobody can't call me!!
}
*/


template<typename Tuple, int N, unsigned Last>
struct Printer
{
    static void print(std::ostream &out, const Tuple &tuple)
    {
        out << std::get<N>(tuple) << ", ";
        Printer<Tuple, N + 1, Last>::print(out, tuple);
    }
    
};


template<typename Tuple, unsigned N>
struct Printer<Tuple, N, N>
{
    static void print(std::ostream& out, const Tuple &tuple)
    {
        out << std::get<N>(tuple);
    }
};














template<typename Tuple, unsigned Left, unsigned Right>
struct Wrapper
{
    static bool palindrome(const Tuple& value)
    {
        if(std::get<Left>(value) != std::get<Right>(value))
        {
            return false;
        }
        return Wrapper<Tuple, Left+1, Right-1>::palindrome(value);
    }
};


template<typename Tuple, unsigned Middle>
struct Wrapper<Tuple, Middle, Middle>
{
    static bool palindrome(const Tuple &value)
    {
        return true;
    }
};







template <bool IsZero>
struct Checker
{
    template <typename... Tuple>
    static bool isPalindrome(const std::tuple<Tuple...> &tuple);
    
    template <typename... Tuple>
    static void printTuple(std::ostream &out, const std::tuple<Tuple...> &tuple);
};


template <>
struct Checker<true>
{
    template <typename... Tuple>
    static bool isPalindrome(const std::tuple<Tuple...> &tuple)
    {
        return true;
    }
    
    template <typename... Tuple>
    static void printTuple(std::ostream &out, const std::tuple<Tuple...> &tuple)
    {
       //Do nothing
    }
    
};


template <>
struct Checker<false>
{
    template <typename... Tuple>
    static bool isPalindrome(const std::tuple<Tuple...> &tuple)
    {
        return Wrapper<std::tuple<Tuple...>, 0, sizeof...(Tuple) - 1>::palindrome(tuple);
    }
    
    template <typename... Tuple>
    static void printTuple(std::ostream &out, const std::tuple<Tuple...> &tuple)
    {
        Printer<std::tuple<Tuple...>, 0, sizeof...(Tuple) - 1>::print(out, tuple);
    }
};



template<typename... Tuple>
std::ostream& operator<<(std::ostream& out, const std::tuple<Tuple...> &tuple) {
    out << "<";
    const bool IsZero = (sizeof...(Tuple) == 0);
    Checker<IsZero>::printTuple(out, tuple);
    out << ">";
    return out;
}



template<typename... Tuple>
bool isPalindrome(const std::tuple<Tuple...> &tuple)
{
    const bool IsZero = (sizeof...(Tuple) == 0);
    return Checker<IsZero>::isPalindrome(tuple);
}










std::string parametersToString(std::string lastParameter)
{
    return lastParameter;
}


template <typename... ArgumentTypes>
std::string parametersToString(std::string currentParameter,
                               ArgumentTypes... arguments)
{
    return currentParameter + ' ' + parametersToString(arguments...);
}


#endif /* variadicTemplates_h */
