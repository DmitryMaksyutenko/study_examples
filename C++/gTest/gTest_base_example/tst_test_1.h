#ifndef TST_TEST_1_H
#define TST_TEST_1_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Test, test_1)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Test, test_1_2)
{
    ASSERT_EQ(3, 3);
}

#endif // TST_TEST_1_H
