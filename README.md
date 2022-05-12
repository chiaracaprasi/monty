# 🐍 Monty 

The goal of this project, part of Holberton School curriculum, is to create an interpreter for Monty ByteCodes files.

![monty_python-crew](https://user-images.githubusercontent.com/91517809/167522780-6fb6cbf8-a8e1-4051-9a4c-5af5dd427718.jpeg)

Monty 0.98 is a scripting language that is first compiled into Monty byte codes, just like Python. It relies on a unique stack, with specific instructions to manipulate it. 

#### 🔍 Monty byte code files

 - Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. 
 - There is not more than one instruction per line. 
 - There can be any number of spaces before or after the opcode and its argument:
 ```
 julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
 - Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
 ```
 julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

## Monty Opcodes

* **push** 
  * Usage: ``push <int> ``
  * Pushe pushes an element to the stack


* **pall** 
  * Prints all the values on the stack, starting from the top of the stack
  * Usage: ``pall``
  * If the stack is empty, don’t print anything


* **pint** 
  * Prints the value at the top of the stack, followed by a new line
  * Usage: ``pint``


* **pop** 
  * Removes the top element of the stack
  * Usage: ``pop``


* **swap** 
  * Swaps the top two elements of the stack
  * Usage: ``swap``
 

* **add** 
   * Adds the top two elements of the stack
   * Usage: ``add``


* **nop** 
   * Doesn’t do anything
   * Usage: ``nop``

* **sub, div, mul, mod** 
   * Performs the respective mathematical operation on the first 2 elements of the stack
   * Usage: ``<opcode>``

* **pchar** 
   * Prints the char at the top of the stack, followed by a new line
   * Usage: ``pchar``

* **pstr** 
   * Prints the string starting at the top of the stack, followed by a new line
   * Usage: ``pstr``


## 📋 Project Requirements 

### General

- All files should end with a new line
- Maximum of one global variable
- No more than 5 functions per file
- Use the C standard library is allowed
- The prototypes of all your functions should be included in the header file called monty.h

### Coding Style

Must follow the ```Betty``` style guide. To install the linter: 

```
$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
```


## 🗝 Usage

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


<!--

# 🗄 Files and Descriptions

|  File Name |         Description         |
|----------------|----------------------------------------------|
| `monty.h` | header file containing all function prototypes
| `main.c` | main file  |
| `file.c` | handles  |
| `file.c` | handles |

-->

## 🪲 Known bugs/limitations

None for now!

## ✍🏽 Authors

- Chiara Caprasi
- Karoline Silva
