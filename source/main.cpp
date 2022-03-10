#include <fmt/format.h>

#include <utils/mymath.h>

using namespace App;
using namespace App::utils::mymath;

int main()
{
    auto result = add(1, 2);
    fmt::print("{0:03d}", result);
}