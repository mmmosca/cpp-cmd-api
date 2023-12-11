# cpp-cmd-api
C++ API for Windows to handle command line parameters with short and long options

## Installation (Windows)
1. Install Visual Studio (e.g. Community) choosing the following `single components`:
    - `.NET SDK`
    - `.NET 7.0 Runtime`
    - `MSVC v142 - C++ Build tools`
    - `MSVC v143 - C++ Build tools`
    - `C++/CLI for Build Tools v142`
    - `Windows 10 SDK (10.2.20348.0)`
    - `CMake C++ Tools for Windows`
    - `Git for Windows`

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
5. When using the library in your project make sure to:
    - Include `<install_folder>/include`
    - Link the static library in `<install_folder>/lib`

## Tests
```
cd build
ctest --build-config Release --build-target install
```

## Usage example
```
int main(int argc, char* argv[]) {
    ...
    while ((w = cmd.mygetoptW(argc, argv, "-o:|opt1:|opt2:|")) != NULL)
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

## Shared library
Shared library can be generated by adding `-DSHARED=ON` to `cmake`:
```
"%VS_DIR%\VC\Auxiliary\Build\vcvarsall.bat" x64_x86
cd cpp-cmd-api
cmake -B build -S . -L -DCMAKE_INSTALL_PREFIX=<install_folder> -DSHARED=ON
cmake --build build --target install --config Release
```
When using the library in your project make sure to:
- Include `<install_folder>/include`
- Link the shared library in `<install_folder>/lib`