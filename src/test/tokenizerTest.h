
#ifndef tokenizerTest_h
#define tokenizerTest_h


#include <utils/Tokenizer.h>

#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK



BOOST_AUTO_TEST_SUITE(TokenizerTestSuite)


BOOST_AUTO_TEST_CASE(Empty)
{
    std::string str;
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.empty());
}


BOOST_AUTO_TEST_CASE(OnlySpaces)
{
    std::string str = " \n \t ";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.empty());
}


BOOST_AUTO_TEST_CASE(OnlySpacesWithoutEraseThem)
{
    std::string str = " \n \t ";
    auto tokens = Tokenizer::Split(str,
                                   '#',
                                   false);
    BOOST_TEST(tokens.size() == 1);
    BOOST_TEST(tokens.front() == str);
}



BOOST_AUTO_TEST_CASE(OneToken)
{
    std::string str = "Hello";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.size() == 1);
    BOOST_TEST(tokens.front() == str);
}


BOOST_AUTO_TEST_CASE(TwoTokens)
{
    std::string str = "Hello#World!";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.size() == 2);
    BOOST_TEST(tokens[0] == "Hello");
    BOOST_TEST(tokens[1] == "World!");
}


BOOST_AUTO_TEST_CASE(TwoTokensSeparatorBeginEnd)
{
    std::string str = "#Hello#World!#";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.size() == 2);
    BOOST_TEST(tokens[0] == "Hello");
    BOOST_TEST(tokens[1] == "World!");
}


BOOST_AUTO_TEST_CASE(TwoTokensConsecutiveSeparators)
{
    std::string str = "Hello###World!";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.size() == 2);
    BOOST_TEST(tokens[0] == "Hello");
    BOOST_TEST(tokens[1] == "World!");
}


BOOST_AUTO_TEST_CASE(FiveTokens)
{
    std::string str = "Hello#World!#I#am#here!";
    auto tokens = Tokenizer::Split(str,
                                   '#');
    BOOST_TEST(tokens.size() == 5);
    BOOST_TEST(tokens[0] == "Hello");
    BOOST_TEST(tokens[1] == "World!");
    BOOST_TEST(tokens[2] == "I");
    BOOST_TEST(tokens[3] == "am");
    BOOST_TEST(tokens[4] == "here!");
}


BOOST_AUTO_TEST_SUITE_END()



#endif /* tokenizerTest_h */
