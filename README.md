<a id="top"></a>
![SimpleDB logo](https://i.imgur.com/UoeOadZ.png)

# SimpleDB

SimpleDB is a simple C++ key-value database project.  
SimpleDB uses features of the lastest stable specification (C++17).  
  
Test cases are made using [Catch2](https://github.com/catchorg/Catch2) framework. See [TODO](TODO) for
more information on the tests.  
  
SimplesDB was testes an is guareteed to run properly on the following specificatios:
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
All storeage will be done as binary in "SimpleDB.db" file whitin ```.\Data\SimpleDB\```.  
  
If the file is not manually deleted all subsequent startups will load the files and read relevant data to primary memory.  
  
After creating a new datase file or loading an existing one the following message will be displayed:
```
Pressione a tecla enter para proseguir!
_
```
Press enter to preceed to the custom CLI, see [TODO](TODO) for more information on the CLI usage.

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
Requires as least one of the following arguments:  
  
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
    - Multi step opretions are easier and painless.
    - Informational feedbacka
* Primary memory indexation:
    - Much faster search operations on secondary memory.
    - Much faster data sorting.
* Huffman and LZW compression/decompression:
    - TODO

## Compiling

Compiling with CMake is implemented and you can build this repository as following:

### Building with CMake:

For standard compilation use the following commands:
```bash
cd ./SimpleDB/
TODO
```

For tests compilation use the following commands:
```bash
cd ./SimpleDB/
TODO
```

The executable file for either cases will be found at `.\Build\build`.  
Run with:
```bash
.\Build\build
```
No arguments necessary, all interactions can be done within the custom CLI.

## License

Distributed under MIT License, see [LICENSE](LICENSE) for more information.

## PUC MINAS - CORAÇÃO EUCARÍSTICO
