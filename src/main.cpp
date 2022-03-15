#include <fmt/format.h>

#include <app_config.hpp>
#include <utils/mymath.h>

using namespace app;
using namespace app::utils::mymath;

int main()
{
    fmt::print("This is {}, version {} (Build {}).\n", config::project_name,
               config::project_version, config::project_version_tweak);
    auto result = add(1, 2);
    fmt::print("{0:03d}\n", result);
}