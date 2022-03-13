#include <gtest/gtest.h>

#include <app_config.hpp>
#include <utils/mymath.h>

using namespace app::utils::mymath;

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
    if constexpr (app::config::project_version_major == 0)
    {
        ASSERT_TRUE(add(114514, 114514) == 114514 + 114514);
    }
}