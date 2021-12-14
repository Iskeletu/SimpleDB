<a id="top"></a>
![SimpleDB logo](https://i.imgur.com/UoeOadZ.png)

# SimpleDB
SimpleDB is a simple C++ key-value database project.  
SimpleDB uses features from C++17 specification.  
  
Test are made using [Catch2](https://github.com/catchorg/Catch2) framework. See [Test Cases](#Test-Cases) for
more information on the tests.  
  
SimplesDB has been tested on the following specificatios:
```bash
OS:             Ubuntu 20.04.3 LTS
Release:        20.04
g++:            (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
```
Other specifications might have unwanted behaviour or not run at all.

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
Press enter to preceed to the custom CLI (see [CLI](#Command-Line-Interface) for more information).

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
Requires one of the following arguments:  

* **'--insert'**:
```bash
simpledb --insert=<[Sorting_Key],[Text]>
```
Generates a unique key and inserts into the database file with "Sorting_Key" as its sorting key value and "Text" as its associated value.  
Example -> `simpledb --insert=<50,example_value>` will create the following key (assuming this is the first insertion on the database file):  
```bash
"Key_1": [
    "Sorting_Key" = 50,
    "Value" = "example_value"
]
```

* **'--remove'**:
```bash
simpledb --remove=<[Key]>
```
Removes a valid key from the database file.  
Example -> `simpledb --remove=<key_1>` will remove the key "key_1" from the database file (assuming this key exists within the database file).

* **'--search'**:
```bash
simpledb --search=<[Key]>
```
Searches the value of a valid key in the database file and returns its sorting key and associated value.  
Example -> `simpledb --search=<key_1>` will display the sorting key and value associated with the key "key_1" in the database file (assuming this key exists within the database file).

* **'--update'**:
```bash
simpledb --update=<[Key],[Sorting_Key],[Text]>
```
Updates the values associated with a valid key.  
Example -> `simpledb --update=<key_1,30,newer_example_value>` will update the key as following (this assumes the database file is the same as the '--insert' argument example):  

**FROM:**
```bash
"Key_1": [
    "Sorting_Key" = 50,
    "Value" = "example_value"
]
```
**TO**
```bash
"Key_1": [
    "Sorting_Key" = 30,
    "Value" = "newer_example_value"
]
```

* **'--list' & '--reverse-list'**:
```bash
simpledb --list=<Key(Operator)[Integer]>
```
```bash
simpledb --reverse-list=<Key(Operator)[Integer]>
```
Lists values based on their sorting key value ('--list' in ascending order and '--reverse-list' in descending order) and the mathematical operator inputted (see [Opeartors](#Implemented_Mathematical_Operators:) for more information).  
Example -> `simpledb --list=<key<=7>` will print to terminal all values from key with a sorting value that is less or equal to seven, `simpledb --reverse-list=<key<=7>` will do the same but the list will be reversed.

### Implemented Mathematical Operators:
-> (=): Sorting key value is equal to the value inputted by the user.   
-> (>): Sorting key value is greater than the value inputted by the user.  
-> (<): Sorting key value is less than the value inputted by the user.  
-> (>=): Sorting key greater or equal to the value inputted by the user.  
-> (<=): Sorting key less or equal to the value inputted by the user.  

* **'--compress' & '--decompress'**:
```bash
simpledb --compress=[Identifier]
```
```bash
simpledb --decompress=[Identifier]
```
Compresses or decompresses the database file based on the identifier inputted (see [Identifiers](#Identifiers:) for more information).  
Example -> `simpledb --compress=huffman` will create a compressed ".hff" file in the database directory, `simpledb --decompress=lzw` will search for a .lzw file and replace the database file with its contents after decompressing it.

### Identifiers:
-> [huffman]: Operation is set to compress the database file with Huffman algorithm or decompress a ".hff" file.   
-> [lzw]: Operation is set to compress the database file with LZW algorithm or decompress a ".lzw" file. 

Note: this functionalitty is not yet implemented.

### Important Notes:
Do not use spaces inside an expression, CLI will recognize that as an extra argument.  
JSON-like template is for example only, database file is binary.

### CLEAR
```bash
SimpleDB > clear
```
Does not support arguments nor expressions, has the same function as a normal bash terminal 'clear' command.

### EXIT
```bash
SimpleDB > exit
```
Does not support arguments nor expressions, initializes save and exit sequence.

## Features
* **Cool start up screen:**
    - Because why not?
* **Custom command line interface:**
    - As user friendly as a terminal interface can be.
    - Easier multi step operations.
    - Informational feedback.
* **Primary memory indexation:**
    - Much faster search operations on secondary memory.
    - Much faster data sorting.
* **Huffman and LZW compression/decompression:**
    - Not yet implemented !**.
* **Make building:**
    - Works out of the box, no configuration or IDE/code editor necessary.

## Building
Building project with **Make** is implemented and you can build this repository as following:

### Building With Make:
  
**For standard compilation use the following commands:**
```bash
cd ./SimpleDB/ (*or equivalent to be at project root directory)
cd ./Make/MainBuild/
make
cd ../../
```

**For tests compilation use the following commands:**
```bash
cd ./SimpleDB/ (*or equivalent to be at project root directory)
cd ./Make/TestsBuild/
make
cd ../../
```

The executable file for either case will be found at `./Build/build`, See [BUILD](./Build/BUILD.md) for more information.  
  
**Run with:**
```bash
./Build/build
```
No arguments required, all interactions can be done within the custom CLI.

## Templates
This repository has a `template.db` file located at ```./Template/Template.db```, this template has 100 unique keys each with its own unique value and a random sorting keys, see [TEMPLATE](./TEMPLATE.md) for more information.

## Test Cases
In total tests have 5 cases and 10 assertions, the tests can be run from the "tests" build (see [Building](#Building) for more information), the tests are as following:
### Database managment Tests
Has two test cases:
* **Database creation and deletion (4 assertions):**
    - Creates and checks if the database object has a valid reference.
    - Checks if the recently created database folder has one file.
    - Checks if the the file is a ".db" file.
    - Deletes and checks if database directory no longer exists.
* **Database loading (2 assertions):**
    - Checks if the loaded database object has a valid reference to an existent file.
    - Deletes the database from the second object reference method and checks if the directory no longer exists.

### Key-Value Tests
Has three test cases:
* **Insertion and search (1 assertion):**
    - Stores and retrive a value from the database and checks if both the local value and the search value match.
* **Insertion and removal (2 assertions):**
    - Stores a value and confirms that the stored key exists within the database file.
    - Removes the value key from within the database and checks if the value is no longer stored in the database file.
* **Insertion and update (1 assertion):**
    - Stores and updates the value of the same key then confirms if the retrieved value matches with the local value used for the update.

### Compression/Decompression tests
Not yet implemented !**.

## License
Distributed under MIT License, see [LICENSE](LICENSE) for more information.

## PUC MINAS - CORAÇÃO EUCARÍSTICO
