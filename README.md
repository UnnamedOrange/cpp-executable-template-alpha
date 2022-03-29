# cpp-executable-template

This is yet another C++ executable template using CMake.

## Features

- [vcpkg](https://github.com/microsoft/vcpkg) as the package manager.
- [googletest](https://github.com/google/googletest) as the unit test framework.
- Continuous integration via [GitHub Actions](https://help.github.com/en/actions/), including build, unit test,  format checking by clang-format and [cmake-format](https://github.com/cheshirekow/cmake_format).
- Redirecting the executable to a clean folder, with assets added beforehand.

Considering the simplicity and the demands, this template does **NOT** includes some critical features.

- **NO** code coverage via any third-party platform, such as [codecov](https://codecov.io/).
- **NO** CMake cached variables to configure sanitizer tools. The sanitizer is only enabled in Debug configuration.
- **NO** documentation configuration.
- **NO** fuzz test or mock test.
- **NO** configuration for warning levels. The warning level is high and warnings are treated as errors.

## Credits and relevant repositories

- [TheLartians](https://github.com/TheLartians) / [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter)

- [cpp-best-practices](https://github.com/cpp-best-practices) / [cpp_starter_project](https://github.com/cpp-best-practices/cpp_starter_project)