
#ifndef templateTest_h
#define templateTest_h

#include <core/templateExamples.h>
#include <magicDataBase/MagicDataBase.h>

#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK



BOOST_AUTO_TEST_SUITE(TemplateTestSuite)


BOOST_AUTO_TEST_CASE(foo1)
{
    MagicDataBase<std::string> dataBase;
    std::string data = "FN-2187";
    bool result = templateExamples::foo1(dataBase,
                                         data);
    BOOST_TEST(true == result);
}



BOOST_AUTO_TEST_SUITE_END()



#endif /* templateTest_h */
