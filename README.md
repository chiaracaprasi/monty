# 🐍 Monty 

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## Project Requirements 

### General

- All files should end with a new line
- Maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called monty.h

### Coding Style

Must follow the ```Betty``` style guide. To install the linter: 

```
$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
```


## Usage

> Step 1 - Clone the repo locally using this command 
```
gh repo clone chiaracaprasi/monty
```
> Step 2 - Navigate to the folder 
```
cd monty
```
> Step 3 - Compiling using this command 
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty 
```

> Step 4 - Run Monty program
```
./monty bytecode_file
```


##  Files and Descriptions

|  File Name |         Description         |
|----------------|----------------------------------------------|
| `monty.h` | header file containing all function prototypes
| `main.c` | main file  |
| `file.c` | handles  |
| `file.c` | handles |

## 🪲 Known bugs/limitations

None for now!

## ✍🏽 Authors

- Chiara Caprasi
- Karoline Silva
