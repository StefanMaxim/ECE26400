# Function Pointer

typedef struct {
    int L;
    int w;
} rectangle;

rectangle r = {3,4};
r.L
r.w //allowed bc r is an object, not a pointer to the object

rectangle* p = &r;
here you have to (*p).L, or just p->L / p->w


##Function Pointer

every function definition in a program has a specific **address**

A function "pointer" is a variable that strores the address of a function

```c
int add(int a, int b)
{
    return a + b;
}

//first int is return type, second two are parameter types:
//note, the parenthesis are to make ti sure that it is a pointer first
int (*fp) (int,int) = &add;

//for normal pointers:
int *p [10] vs int (*p) [10] //array of 10 integer pointers, vs pointer to an array of 10 integers.


//HUH? since internally, &add and add are the same, you can use either
// &add is the address of the function. add internally is treated teh same way
// ADD DECAYS TO THE POINTER TO THE FUNCTION ANYWAYS WHEN INVOKED
// KIND OF LIKE HOW ARRAYS DECAY TO A POINTER TO THEIR FIRST ELEMENT.
int x = fp(1,2);
int y = (*fp)(3,4); 

```

lets suppose you want another 

```c
Operator fp = &add; //where &add == add
```

Operator??? use typedef
```c
typedef int(*Operator)(int,int); //A USER-DEFINED TYPE, so now operator can reference the object
```
THIS IS MORE CONVENIENT BC IF YOU NEED ANOTHER FP REFERENCING ADD, CAN USE THE OPERATOR 


int add(int a, int b)
{
    return a+b;
}

int substract(int a, int b)
{
    return a-b;
}
...(many similar functions with same return type and same parameters)


int apply(int a, int b, int op)
{
    int return_value;
    switch (op)
    {
        case 0:
            return_value = add(a,b);
            break;
        case 1:
            return_value = substract(a,b);
            break;
        ...
    }
    return return_val
}

This is a poor program design. Suppose you want to add a new function, maybe divide. 
Now, you have to rewrite the apply function to add another case in the client program.


typedef int (*Operator) (int,int);

int apply(int a, int b, Operator op)
{
    return op(a,b);
}

here, can just apply(a,b,&divide);

Now, thats much better!!


## Arrays of Function Pointers

Suppose you have some array, where every type is of type operator. 
```c
Operator arr[4] = {&add, &subtract, &multiply, &divide}; //Again, you can remove & whenever

arr[2](3,4);

//of course, can also just do:

int (*arr[4])(int,int) = {}; //star retrieves the value of the pointer (which we want, ie the function itself)

```


## GDB:

Be sure to attend the GDB demo on Feb 2 or Feb 4 in arms 1028 (more details in post and in the pic you took)

What is GDB? it is a command line debugger.

**USEFUL BC**
stop at specific line (break point)
see the value of a variable
see stack memory
etc



## String

Type vs Value vs Expression:

Type: 
exe: to say h, the computer has bytes: h = 01101000 (8 bit/1byte)

can convert the number into its equivalent decimal number 104 = 01101000

How does the program know how to interrpet these bytes, h or 104 or 1001000? that is the type.
type is a way of interpreting bytes in the computer.

BUT ITS MORE THAN THAT: 
int x;
1) you specify the range of x (-2^31 to 2^31 - 1) decimal number
(reason: there are 4 bytes/32 bits, with the leftmost being a sign bit.)
largest value is filling in the first as 0 and the rest ones. 
0x1 = 1
0x11 = 3 = 2^2 - 1
0x1111...1 = 2^31 - 1 since first one is signed bit, so only 31 bits remaining, and then its -1 bc of the 2^0 = 1

what about negative 1?
100...01? no, thats ones compliment (makes there be two zeros)
TWOS COMPLIMENT:
first find the positive version:
000...01 for 1
then flip all the bits
111...10
lastly, add 1:
1111...1
that is negative 1

2) Memory Size
sizeof(int) = 4 bytes
printf("%lu",sizeof(int)); //lu bc has to be unsigned long (size cannot be negative)

explation:

int x = 104;
printf("%d",x); displays 104
printf("%c",x); displays "h"

thats why lu because the bytes there of sizeof are of type lu, so if you dont display it this way it might be wrong




3) defined legal operators

1/2 = 0.5 (NO) = 0 
"hello" / "bye" (not permitted, since division is defined for integrable operands)



int is a group of **values**: inside here are the numbers 1,2,3,...

Value is a conceptual idea. the value exists only inside of your mind. 
How do you show something:


exe: you have the idea of two things in your head

to show, must draw something like: * * 

to show the idea to others, you have to use an **expression** (the stars in this case)

IE: the value of two is represented by two two bits, 10, which are transistors being on or off, that is their expression

is "3" a value? NO, is "3+4" a value? NO. They are expressions. 



**CRUTIAL**
> A type is a category of values
> An expression evaluates to a value
> Expression is notation (syntax)
> Value is semantics



## Back to Strings:

**NOTE** C has to string data type

String is an array of characters that ends with NULL ("\0")
each element is a one byte character that stored values between 0 and 255
since 16 * 16 = 256 different characters, or 0 to 255

char arr1[] = {'T','h','i','s'}; //not a string
char arr1[] = {'T','h',"i",'s','\0'}; //this is a string of size 4 (null not counted, it is delimiter)

how to print out the string:

printf("%s",&arr3[0]); //will print the array untill the first null character.

char* p = arr3; //value here is &(arr[0])
printf("%s",p); //words as well


can also make an array of char* , or functionally an array of character array pointers.
call the pointer to this char*(*q) or char** q, for a pointer to an array of strings.
functionally a 2d array. 

Where q is the address of the first element of the first string
