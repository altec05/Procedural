#include "gtest/gtest.h"
#include "numbers.h"
#include "container.h"

using namespace std;
using namespace testing;

string input_str = "input.txt";
string output_str = "output.txt";

TEST(TESTS, Testing_Input) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    ASSERT_NO_THROW(In(c, ifst));
}

TEST(TESTS, Testing_Output) {
    ofstream ofst(output_str);
    variant9123::numbers_array c{};
    Out(c, ofst);
}

TEST(TESTS, Testing_Clear) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    In(c, ifst);
    ASSERT_NO_THROW(Clear(c));
}

TEST(TESTS, Testing_ignore) {
    ifstream ifst(input_str);
    ofstream ofst(output_str);
    variant9123::numbers_array c{};
    In(c, ifst);
    ASSERT_NO_THROW(Out(c, ofst, variant9123::types::POLAR));
    Clear(c);
}


TEST(TESTS, Testing_overflow) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    In(c, ifst);
    EXPECT_EQ(Overflow_test(c), 0);
    Clear(c);
}