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

## Guides of this template

Thank you for choosing this template! Below are the recommended usages of it. I assume that you are running your computer on Windows --- if not, I believe you are adequately capable of finding corresponding solutions on your own.

### Install [Visual Studio](https://visualstudio.microsoft.com/)

Although CMake Application tends to be cross-platform, it is required to install Visual Studio on Windows before using the package manager vcpkg. For individual developers, please download the Community distribution for free.

The core of Visual Studio includes an advanced code editor and an elaborate project manager. However, there is no compiler to be installed by default, so before starting to install, you should check desktop applications in C++ to install the compiler *MSVC*. **For this template, you should also check *C++ AddressSanitizer*.** Other options, such as CMake and Google Test Adapter, are unnecessary.

For non-English users, it also requires installing the English language pack to make vcpkg work well.

### Setup [vcpkg](https://github.com/microsoft/vcpkg)

You can simply follow [the official guide](https://github.com/microsoft/vcpkg#quick-start-windows).

## Credits and relevant repositories

- [TheLartians](https://github.com/TheLartians) / [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter)

- [cpp-best-practices](https://github.com/cpp-best-practices) / [cpp_starter_project](https://github.com/cpp-best-practices/cpp_starter_project)