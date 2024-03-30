# cpp-cmd-api
C++ API for Windows to handle command line parameters with short and long options

## Installation (Windows)
1. Install Visual Studio (e.g. Community) choosing the following `single components`:
    - `MSVC v142+ - C++ Build tools`
    - `C++/CLI for Build Tools v142+`
    - `Windows 10 SDK (10.2.20348.0+)`
    - `CMake C++ Tools for Windows`

2. Download the repository

3. Add the following environmental variable as User:
    - `VS_DIR`: Path to Visual Studio with all folders (e.g. `Microsoft Visual Studio\2022\Community`)

4. Run the following in a `Command Prompt` (no PowerShell) to install it:
    ```
    "%VS_DIR%\VC\Auxiliary\Build\vcvarsall.bat" x64_x86
    cd cpp-cmd-api
    cmake -B build -S . -L -DCMAKE_INSTALL_PREFIX=<install_folder>
    cmake --build build --target install --config Release
    ```
    Note: Generate shared libraries (`.lib` + `.dll`) instead as follows:
    ```
    cmake -B build -S . -L -DCMAKE_INSTALL_PREFIX=<install_folder> -DSHARED=ON
    ```
5. When using the library in your project make sure to:
    - Include `<install_folder>/include`
    - Link the library `<install_folder>/lib/cmd-api.lib`


## Load `cmd-api` as dependency in your cmake file
In your `CMakeLists.txt` file
```
...
find_package(cmd-api PATHS "<install_folder>" REQUIRED)
include_directories(${cmd-api_INCLUDE_DIR})
add_executable(${PROJECT_NAME} yourmain.cpp)
target_link_libraries(${PROJECT_NAME} "${cmd-api_LIBRARIES}")
install(FILES ${cmd-api_RUNTIME} DESTINATION bin)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
...
```

## Usage example
```
#include "cmd-api.h"
int main(int argc, char* argv[]) {
    CommandLine cmd;
    char* w;
    while ((w = cmd.mygetoptW(argc, argv, "o:|opt1:|opt2:|")) != NULL)
    {
        if (strcmp(w, "o") == 0) {
            /*use cmd.myoptarg that has the argument of o*/
            continue;
        }
        if (strcmp(w, "opt1") == 0) {
            /*use cmd.myoptarg that has the argument of opt1*/
            continue;
        }
        if (strcmp(w, "opt2") == 0) {
            /*use cmd.myoptarg that has the argument of opt2*/
            continue;
        }
    }
    ...
}
```

## Tests (only on static build)
```
cmake -B build -S . -L -DCMAKE_INSTALL_PREFIX=<install_folder>
cd build
ctest --build-config Release --build-target install
```
