# Lecture 3:

## HW#2 Important Code
Given Code:


int main(int argc, char** argv)

argc = number of arguents
argv = argument strings

gcc ext1.c
./aout **hello bye 123** (the arguments)

NOTE: the execution file name itself is an arument (thus 4 arguments)
argc = 4;
argv = char double pointer, or essentially an array of strings (an array of pointers that point to strings)

> **NOTE** 
> argv and argc are defined in c?

```Makefile
test1: all
    ./$(EXEC) 6 3 > output1
```
argv[0] = ./ex1
argv[1] = 6
argv[2] = 3
(this runs the file EXEC dereferenced with arguments 6 and 3 and redireects the  standard output to output1)
How does program not know the > symbol?: THE CARROT DOESNT MAKE IT TO THE PROGRAM, ITS PARSED BY THE TERMINAL

### Valgrind
Valgrind: tool for checking if you have any memory leakage. It is a phony target(explaining further)

#### Phony Target
Consider Makefile:
```Makefile
x: y
    ls

y: 
    pwd
```
When running make command with makefile, goal is to create x.
to create x, run the dependency bc x is outdated.
However, if x exists, it will do nothing bc x is up to date. 

Thus, you have to tell computer to the makefile that x isn't a real file, so just allways do it

```Makefile
.PHONY: x y
```
(this means that it will run the commands for x and y without checking that it is up to date or not)

## Stack Memory:

### Main Memory:
In computer, two types of Memory:
- Main Memory (Random Access Memory)
- Secondary Memory (ex Hard-disk)

What is difference?
1. Price (RAM is disgustingly priced)
2. Main Memory is volatile, meaning all the memory stored there is gone
3. Memory is accessed in terms of **bytes**
4. **Each byte has its own address**  
Can be 32 or 64 bit (meaning 4 bytes or 8 bytes for an address)
> In 32 bit, thats 2 to the 32 addresses (around 2 billion) or $2^{64}$ bytes (because each byte has its own address)
> In 64 bit, thats 2 to the 64 addresses (massive)

### Memory Management:
Every program has access to the entire memory.

Thus, is 64bits -> $2^{64}$ addresses
$2^{64}$ bytes or 2^4 times 2^10 times 2^10 times 2^10 Gigabytes.
or roughly 16 billion Gigabytes

BUT my machine has only 16 GB?

Operating System mediates all access to hardware, and uses virtual memory to create the illusion of a huge memory space.
(Program assumes there are allways 16 billion GB available, but)

OS allocates memory **on request** and **on demand**

### Back to Stack:
Stack is an ADT, or Abstract Data Type. (data type = int, short, long)

Abstract: Conceptual Idea.

Abstractly, Stack si like a stack of pancakes. LIFO datatype.
push: operation to add to stack
pop: operation to remove from stack
peek: see the first element without popping it

Top: the top is the first item on the stack.

How to impliment stack? easiest way is to use an array:

Array Arr:
|0      |1       |2
|A      |B       |C

Note: you can retrieve the element at index 0, but then you violate the stack


### Operands
Note: FIRST, evaluate operands first L -> R
Then, once all of your operands are evaluated, then consider operator precedence.

EX:
f(1) + f(2) * f(3)
THE FIRST THING YOU DO IS GO LEFT TO RIGHT AND EVALUATE f(1) f(2) f(3)


> NOTE: to figure out what a program does, draw a STACK:
int x = 3
int y = 5
f(x,y) + x + f(y,x)
(comma means value change)

10      9       8       7       6       5
main    f(x,y)
x=3     x=3,5
y=5     y=5,3
(not the same x and y bc of scope)
once the function is done, pop off the stack and push another one on

Parameters vs Arguments: Parameters is what they are called in the function, and arguments are the things you pass
to the function

### Stack Frame:

stack frame is a further allocated piece of memory given to the stack to store locals (bare stack is just return address)




