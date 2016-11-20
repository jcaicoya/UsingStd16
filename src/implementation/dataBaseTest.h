
#ifndef dataBaseTest_h
#define dataBaseTest_h


#include <utils/DataBaseImpl.h>

#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK


extern template class DataBaseImpl<std::string>;


BOOST_AUTO_TEST_SUITE(DataBaseTestSuite)


BOOST_AUTO_TEST_CASE(Empty)
{
    DataBaseImpl<std::string> db;
    BOOST_TEST(0 == db.size());
}


BOOST_AUTO_TEST_CASE(InsertTwoElements)
{
    DataBaseImpl<std::string> db;
    
    std::string finn = "FN2187";
    db.insert(finn);
    BOOST_TEST(db.size() == 1);
    BOOST_TEST(db.contains(finn));
    
    std::string robot = "BB8";
    db.insert(robot);
    BOOST_TEST(db.size() == 2);
    BOOST_TEST(db.contains(robot));
}


BOOST_AUTO_TEST_CASE(InsertErase)
{
    DataBaseImpl<std::string> db;
    
    std::string finn = "FN2187";
    db.insert(finn);
    BOOST_TEST(db.size() == 1);
    BOOST_TEST(db.contains(finn));
    
    db.erase(finn);
    BOOST_TEST(db.size() == 0);
    BOOST_TEST(!db.contains(finn));
}



BOOST_AUTO_TEST_SUITE_END()

#endif /* DataBaseTest_h */
