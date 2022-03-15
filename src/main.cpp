#include "app_config.hpp"
#include "utils/mymath.h"

#include <fmt/format.h>
#include <fstream>

using namespace app;
using namespace app::utils::mymath;

int main()
{
    fmt::print("This is {}, version {} (Build {}).\n", config::project_name,
               config::project_version, config::project_version_tweak);

    std::ifstream ifs("content.txt");
    std::string line;
    std::getline(ifs, line);

    auto result = add(1, 2);
    fmt::print("{0:03d}: {1}\n", result, line);
}