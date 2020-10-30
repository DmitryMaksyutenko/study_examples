#ifndef TST_TEST_2_H
#define TST_TEST_2_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Test, test_2)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_TEST_2_H
