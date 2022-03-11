#include <gtest/gtest.h>

#include <utils/mymath.h>

using namespace App::utils::mymath;

/**
 * @brief Test basic adds.
 *
 */
TEST(mymath, basic_test)
{
    ASSERT_EQ(add(1, 2), 3);
}

/**
 * @brief Test 114514 + 114514.
 *
 */
TEST(mymath, more_test)
{
    ASSERT_TRUE(add(114514, 114514) == 114514 + 114514);
}