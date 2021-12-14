# BUILD
This is the default directory binary executables will be located, both the test cases build and the main build have the sabe binary file name, so building will replace 
existing binary files.  

## Flags
**Make** is set to give g++ compiler the `-std=c++17` flag, so g++ needs to be recent enough to support C++17.
Include path is set at ./{PorjectRoot}/Include.

## Main Build
Compiles the following files:

* commandhandler.cpp
* database.cpp
* datacell.cpp
* dbhandler.cpp
* huffman.cpp
* index.cpp
* lzw.cpp
* quicksort.cpp
* screens.cpp
* simpledb.cpp

## Tests Build
Compiles the following files:

* database.cpp
* datacell.cpp
* db_management_tests.cpp
* dbhandler.cpp
* huffman.cpp
* index.cpp
* lzw.cpp
* quicksort.cpp
* key-value_tests.cpp