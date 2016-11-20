
#ifndef templateExamplesTest_h
#define templateExamplesTest_h

#include <implementation/templateExamples.h>
#include <utils/DataBase.h>

#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK



BOOST_AUTO_TEST_SUITE(templateExamplesTestSuite)


BOOST_AUTO_TEST_CASE(foo1)
{
    DataBase<std::string> dataBase;
    std::string data = "FN-2187";
    bool result = templateExamples::foo1(dataBase,
                                         data);
    BOOST_TEST(true == result);
}



BOOST_AUTO_TEST_CASE(foo2)
{
    DataBase<std::string> dataBase;
    std::string data = "FN-2187";
    bool result = templateExamples::foo2(dataBase,
                                         data);
    BOOST_TEST(true == result);
}



BOOST_AUTO_TEST_CASE(foo3)
{
    DataBase<std::string> dataBase;
    std::string data = "FN-2187";
    bool result = templateExamples::foo3(dataBase,
                                         data);
    BOOST_TEST(true == result);
}


BOOST_AUTO_TEST_CASE(foo4)
{
    //TODO//
    /*
    std::vector<int> noDataBase;
    double value = 15.15;
    bool falseResult = templateExamples::foo4(noDataBase,
                                              value);
    BOOST_TEST(false == falseResult);
     */
    ////////
    
    DataBase<std::string> dataBase;
    const double PI = 3.14159263;
    bool result = templateExamples::foo4(dataBase,
                                    PI);
    BOOST_TEST(true == result);
    
    std::string data = "FN-2187";
    result = templateExamples::foo4(dataBase,
                                    data);
    BOOST_TEST(true == result);
}




BOOST_AUTO_TEST_CASE(foo5)
{
    //TODO//
    /*
     std::vector<int> noDataBase;
     double value = 15.15;
     bool falseResult = templateExamples::foo4(noDataBase,
     value);
     BOOST_TEST(false == falseResult);
     */
    ////////
    
    DataBase<std::string> dataBase;
    const double PI = 3.14159263;
    std::string data = "FN-2187";
    bool result = true;
    int testNumber = 5;
    
    result = templateExamples::foo5(dataBase,
                                    PI,
                                    data,
                                    result,
                                    testNumber);
    BOOST_TEST(true == result);
}



BOOST_AUTO_TEST_SUITE_END()



#endif /* templateExamplesTest_h */
