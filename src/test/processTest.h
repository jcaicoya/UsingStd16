
#ifndef processTest_h
#define processTest_h


#include <magicDataBase/MagicDataBase.h>
#include <core/ProcessMessage.h>

#include <boost/test/unit_test.hpp>



#define BOOST_TEST_MODULE testModule


struct DataBaseFixture
{
    DataBaseFixture() : dataBase() { BOOST_TEST_MESSAGE("setup fixture"); }
    ~DataBaseFixture()             { BOOST_TEST_MESSAGE("teardown fixture"); }
    
    MagicDataBase<std::string> dataBase;
};


BOOST_FIXTURE_TEST_SUITE(testSuite, DataBaseFixture)


BOOST_AUTO_TEST_CASE(Init)
{
    BOOST_TEST_MESSAGE("Test case: Init");
    BOOST_TEST(dataBase.empty());
}


BOOST_AUTO_TEST_CASE(CreateFirstElement)
{
    BOOST_TEST_MESSAGE("Test case: CreateFirstElement");
    
    const char * message = "1#C#FN-2186";
    processMessage(message, dataBase);
    
    BOOST_TEST(dataBase.contains("FN-2186"));
    BOOST_TEST(dataBase.size() == 1);
}


BOOST_AUTO_TEST_CASE(CreateSecondElement)
{
    BOOST_TEST_MESSAGE("Test case: CreateSecondElement");
    
    const char * message = "2#C#FN-2187";
    processMessage(message, dataBase);
    
    BOOST_TEST(dataBase.contains("FN-2186"));
    BOOST_TEST(dataBase.contains("FN-2187"));
    BOOST_TEST(dataBase.size() == 2);
}


BOOST_AUTO_TEST_CASE(EraseSecondElement)
{
    BOOST_TEST_MESSAGE("test case: EraseSecondElement");
    
    const char * message = "3#E#FN-2187"
    processMessage(message, dataBase);
    
    BOOST_TEST(dataBase.contains("FN-2186"));
    BOOST_TEST(dataBase.size() == 1);
}


BOOST_AUTO_TEST_CASE(EraseFirstElement)
{
    BOOST_TEST_MESSAGE("Test case: EraseFirstElement");
    
    const char * message = "4#E#FN-2186"
    processMessage(message, dataBase);
    
    BOOST_TEST(false == dataBase.contains("FN-2186"));
    BOOST_TEST(dataBase.size() == 0);
}


BOOST_AUTO_TEST_CASE(End)
{
    BOOST_TEST_MESSAGE("Test case: End");
    BOOST_TEST(dataBase.empty());
}


BOOST_AUTO_TEST_SUITE_END()



#endif /* processTest_h */
