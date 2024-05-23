# LogiParser

LogiParser is a C++ application that extracts messages and their respective sequence number from the logi.bin file.

## Building using CMake

A CMake file is provided to aid the build process. The following is an example building the application using cmake and MinGW compiler.

```bash
"C:\Program Files\CMake\bin\cmake.exe" --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=C:\msys64\ucrt64\bin\gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=C:\msys64\ucrt64\bin\g++.exe -SC:/Users/dvicente/dev/LogiParser -Bc:/Users/dvicente/dev/LogiParser/build -G "MinGW Makefiles"
"C:\Program Files\CMake\bin\cmake.exe" --build c:/Users/dvicente/dev/LogiParser/build --config Debug --target all -j 22 --
```

## Running application

```bash
cd build
.\LogiParser.exe ..\logi.bin 

+-----------------+--------------------------------------+
| Sequence Number | Message                              |
+-----------------+--------------------------------------+
  0               | Hello, welcome to Logitech!
+-----------------+--------------------------------------+
  1               | Open and Ourselves
                  | Hungry but Humble
                  | Collaborate but Challenge
                  | Decide and Do
                  | Equality and Environment
+-----------------+--------------------------------------+
  2               | This is the final message, Goodbye
+-----------------+--------------------------------------+

```

## Possible Improvements
- Error handling - Since the test assures that the input file is correct, the solution skips certain validation, but for a real application better validation when parsing the file is essential.
- Message display - More flexible or different way of displaying the messages if the input changes. 