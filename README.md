<a id="top"></a>
![SimpleDB logo](https://i.imgur.com/UoeOadZ.png)

# SimpleDB

SimpleDB is a simple C++ key-value database project.  
SimpleDB uses features from C++17 specification.  
  
Test cases are made using [Catch2](https://github.com/catchorg/Catch2) framework. See [Test Cases](#Test-Cases) for
more information on the tests.  
  
SimplesDB has been tested on the following specificatios:
```bash
OS:             Ubuntu 20.04.3 LTS
Release:        20.04
g++:            (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
```
Other specifications might have unwanted behaviour or not run at all.  
Windows is currently not supported.

## Starting Up

SimpleDB will create a default ```.\Data\``` directory for database storage within the top level project folder.  
  
The default database name is called "SimpleDB", a subfolder with that name will be created shortly after.  
All storage will be done as binary in "SimpleDB.db" file whitin ```.\Data\SimpleDB\```.  
  
If the file is not manually deleted all subsequent startups will load the file and read relevant data to primary memory.  
  
After creating a new datase file or loading an existing one the following message will be displayed:
```
Pressione a tecla enter para prosseguir!
_
```
Press enter to preceed to the custom CLI, see [CLI](#Command-Line-Interface) for more information on the CLI usage.

## Command Line Interface
SimpleDB runs on a custom command line interface (CLI).  

The following commands are supported:

### HELP
```bash
SimpleDB > help [*arg]
```
Can be used with arguments to show available commands or with a command as argument to show usage.  
Does not support expressions.  

### SIMPLEDB
```bash
SimpleDB > simpledb [arg]=<exp>
```
Supports expressions.  
Requires one of the following arguments:  
  
TODO

### CLEAR
```bash
SimpleDB > clear
```
Does not support arguments nor expressions, has the same function as a normal bash terminal clear command.

### EXIT
```bash
SimpleDB > exit
```
Does not support arguments nor expressions, initializes save and exit sequence.


## Usage

TODO

## Features

* Custom command line interface:
    - As user friendly as a terminal interface can be.
    - Multi step operations are easier and painless.
    - Informational feedback.
* Primary memory indexation:
    - Much faster search operations on secondary memory.
    - Much faster data sorting.
* Huffman and LZW compression/decompression:
    - Less disk space usage.
    - TODO.
* Make building:
    - Works out of the box, no configuration or IDE necessary.

## Building

Building project with **Make** is implemented and you can build this repository as following:

**OBS:: Needs Make and g++ compiler installed.**

### Building with Make:

For both building cases a `./Build/` directory needs to be created at the project root folder.
  
For standard compilation use the following commands:
```bash
cd ./SimpleDB/
cd ./Cmake/MainBuild/
make
cd ../../
```

For tests compilation use the following commands:
```bash
cd ./SimpleDB/
cd ./Cmake/TestsBuild/
make
cd ../../
```

The executable file for either case will be found at `.\Build\build`.  
  
Run with:
```bash
./Build/build
```
No arguments required, all interactions can be done within the custom CLI.

## Templates

This repository has a `template.db` file located at ```./Template/Template.db``` template with 100 unique keys each with its own unique value and a random sorting keys, see [TEMPLATE](https://github.com/Iskeletu/SimpleDB/blob/main/Template/TEMPLATE.md) for more information.

## Test Cases

### Database managment tests

Has two test cases:

* Database creation and deletion (4 assertions):
    - Creates and checks if the database object has a valid reference.
    - Checks if the recently created database folder has one file.
    - Checks if the the file is a .db file.
    - Deletes and checks if database direcoty no longer exists.
* Database loading (2 assertions):
    - Checks if the loaded database object has a valid reference to an existent file.
    - Deletes the database from the second object reference method and checks if the direcoty no longer exists.

### Key-Value tests

Has three test cases:

* Insertion and search (1 assertion):
    - Stores and retrives a value from the database and checks if both values match.
* Insertion and removal (2 assertions):
    - Stores a value and confirms that the stored key existis within the database file.
    - Removes its key from within the database and checks if the value is no longer stored in the database file.
* Insertion and update (1 assertion):
    - Stores and updates the value of the same key then confirms if the retrieved value matches with the local value used for the update.

### Compression/Decompression test

TODO  
  
Tests have a total of 5 cases and 10 assertions, the tests can be run from the "tests" build, see [Building](#Building) for more information.

## License

Distributed under MIT License, see [LICENSE](LICENSE) for more information.

## PUC MINAS - CORAÇÃO EUCARÍSTICO
