# String Of Characters

char arr[] = {'x','?',' ','\0'};
printf("%s",arr); //to print the string on the screen. string of length 5 actually has 6 elements

first element in array is arr[0]
*(&arr[0]) = *arr(since arr stored the address of the address)

char* p = arr; //do this work? yes since arr is type char*(when it decays) since it points to arr[0], 
aka holds value &arr[0]

can you do p[0], p[1], ...
yes, since anyways the preprocessor converts arr[0] to *(arr + 0) = *(&arr[0] + 0)
(not pre-processor, but they function semantically the same)
(the C AST does simplify the array access to a pointer arithmetic thought )

**REMEMBER** *(p+1)this increments forward one BYTE.

(char*)* argv = &p // in other words, you are defining a pointer to a char pointer to be equal to the address
of p, the curent address. 

WHY is this useful:
because argv doesnt have to be a single char, it can be an array of characters.
In others words, argv is now an array of character arrays, or an array of strings functionally. 
Since again, only need to know the address of the first element of the array, so you can either
have a pointer char** to a character pointer char*, whcih is pointing to a character char OR
an array of pointers char** to an array of chars char*.

basically, it is a two dimensional array.
argv[2][3] lets you access argvs second element, dereference it, and then go to its third element.

&(argv[2]) = argv + 2; //address of first element. where 

**NOTE** argv has value of p, p has address, which is 8 bytes, so argv + 1 doesnt move 1 byte, rather
8 bytes!!!

what about argv[2], this has address of the first byte of some other array. *(argv[2] + 3), is address of 4th element
here, you are shifting 3 bytes, NOT 24 because it is of the type that the pointer is pointing to , since pointing to 
a char, it is 3*sizeof(*argv[2]) = 3


> **NOTE**:
(*(argv + 2))[3] is not the same as *(argv+2)[3] = *(argv + 5)

WHY: *(argv+2)[3] = *(argv+2 +3) = *(argv + 5)


OKAY, what about the difference between:
char arr[10][20]; //here, memory allocation determined at compile time

VS:

char** arr = malloc(sizeof(char*) * 10);
for(int i = 0; i < 10; i++)
{
    arr[i] = malloc(sizeof(char) * 20);
}

here, memory allocation is done at runtime. NOTE: you have to use malloc since given some pointer
*(arr + 1) will most likely segfault if you havent allocated memory for it.

malloc will return a void pointer, which is still 8 bytes, which it read into the array values.

Note: when there is only one statment in the body of a for loop, you do not have to use curly brances

what about double for loops:

for(int i = 0; i < 20; i++)
    (SINGLE)
    for(int i = 0; i < 20; i++)
        printf("hello world");
        printf("wassup");
    (STATMENT)

this is legal, because a for loop statment is allways a single statment.(SAME WITH IFs)



char** argv= malloc(sizeof(char*) * 10);
now, there are 10 consecutive 8-byte buckets, with a head of void pointer that is now equal to the char** argv.

argv[0] is the value at the first element of the array, ie the address of one of the strings
&argv[0] is the address of the first byte of the first value of the array
(this is also equal to argv, or at least it will decay to it)

sizeof(argv + 0)// still 8 bytes **CONFUSING**
This is the same as asking sizeof(char**), which is just 8 bytes.



## Command Line Arguments;


./a.out abc def 123

in the argv, the first element is pointing to ./a.out\0, second to abc\0, third def\0
of course, it pointing to the address of the first bytes of these strings.

argc value is 4, the number of entries

int main(int argc, char** argv)
{
    int i;
    printf("argc = %d\n",argc);



    return EXIT_SUCCESS; //instead of return 0, use EXIT_SUCCESS, defined in stdlib.h
}

#define EXIT_SUCCESS 0


remember:
ex1.c - > ex1.i (in here will find the #define EXIT_SUCCESS 0)

DRAW a stack to understand how stuff works.
answer: nothing changes, even though pointers are used, since you are not dereferencing them, just passing
their values.

instead pass int* and then int**.
(review all this stuff asap)

to print out 2 insteaf of 1, pass down a chain of pointers down the functions
for xyz, pass down pointer to a pointer of type char. 