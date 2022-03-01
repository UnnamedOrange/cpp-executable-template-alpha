#include <iostream>
#include <string>

#include <fmt/format.h>

int main()
{
    auto str = fmt::format("{1:d}", 233);
    std::cout << str << std::endl;
}