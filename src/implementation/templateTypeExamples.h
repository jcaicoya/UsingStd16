

#ifndef templateTypeExamples_h
#define templateTypeExamples_h

#include <boost/lexical_cast.hpp>

#include <iostream>


namespace templateExamples
{

template <bool Condition>
struct CompileTimeEvaluator;


template <>
struct CompileTimeEvaluator<true>
{};

    
    
template <int ParticularValue>
struct ParticularValueType
{
    enum { value = ParticularValue };
};



class Strategy
{
public:
    template <int AlgorithmType,
              typename Container>
    static void Execute(int algorithmType, Container &container)
    {
        Algorithm(container,
                  ParticularValueType<AlgorithmType>());
    }
    
private:
    template <typename Container>
    static void Algorithm(Container &container, ParticularValueType<1>)
    { std::cout << "Algorithm One" << std::endl; }
    
    template <typename Container>
    static void Algorithm(Container &container, ParticularValueType<2>)
    { std::cout << "Algorithm Two" << std::endl; }
    
    template <typename Container>
    static void Algorithm(Container container, ParticularValueType<3>)
    { std::cout << "Algorithm Three" << std::endl; }
};
    
 


    
    
} //end namespace


#endif /* templateTypeExamples_h */
