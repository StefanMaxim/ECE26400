fscanf

char arr[101];
while (fgets(arr,100,fp) != NULL)
{

}
Exe: suppose page has
(120 chars) \n
(80 chars) \n
(110 chars)

Will first read 100/120 chars at first iteration.
Next, read remaining 20 (why only 20: because of the /n, it will read line feed and then stop)
Third iteration, 80 and then new line.
Fouth 100
Fifth 10 and \n

Will not include \n in the array.



## ftell

by default, the file pointer is 0
int ch = fgetc(fp);
printf("ftell = %ld\n", ftell(fp));

tells which will be read next. IE starts at 0, after reads 0 goes to 1.
etc, will be the offset from the start of the file.

after reading the null at the end, it will move the pointer again to after the null, and then return



## fseek
moves the offset in the file

fseek(fp, 6, SEEK_SET); // move 6 bytes from the initial pt, (now at index 6, the 7th byte in the file)
file pointer fp
offset 6, by how many bytes to move
SEEK_SET is where to start from. 

fseek(fp, 6, SEEK_CUR); move 2 bytes from the current value
fseek(fp, -1, SEEK_END); moves 1 byte before the end. SEEK_END is number of bytes (ie one past the last index)


## fread / fwrite 
Used for binary reading





# Heap

int* arr = malloc(5 * sizeof(int));
//same as int arr[5]; malloc keeps track of the fact that there is type int[5], and returns the start address of this object

free(arr); (this proves it must have a table telling you what it it)

Difference:
first arr is a pointer to an int in memory (or at least it functions like it)

second array is type int[5], not a pointer, but decays to a pointer. (in the syntax table it shows up as type int[5])

sizeof(arr) = 8 (integer pointer)
sizeof(arr) = 4*5 = 20 (because it is type int[5])

if(arr == FULL)
{
    return EXIT_FAILURE;
}


Segments of Code:
Stack Segment, Heap Segment, Data segment, Code Segment.
Stack is upside down.

int* ptr = malloc();
prt has address in heap memory space.

global variables are in teh data segments.

static variables are in a function body, yet it is in teh .bss section.

void f()
{
    static int x =0;
    x++;
    printf("%d",x);
}
int main()
{
    f();
    f();
    f();
}

> **NOTE**

Static = remember its value???(WTF i thouht it was in read-only memory)

static local variable will be initialized only once. 
for this case, do not write inside of the box.

HOWEVER: x is still a local variable, just persistent

static vs global:
global = global lifetime, global scope
static = global lifetime, local scope

Note: multiple symbol tables, containing
file scope, function scope, and block scope symbol tables. 
Thus, when 

When the compiler sees an identifier:

It starts in the current scope

If not found, it walks outward (block → function → file)

If still not found → compile-time error

So for a static local, lookup simply never finds it outside the function body.

NOTE: USUALLY, THEY HAVE A STACK/TREE OF SCOPES, NOT SEPARATE TABLES

(scope vs linkage): scope = where can I name this variable, linkage = can other translational units refer to this here.

# 2D Arrays:

int **arr = malloc(r * sizeof(int*));

for(int i = 0; i < r; i++)
{
    arr[i] = malloc(c * sizeof(int));
}

// HAVE TO FREE IN ORDER YOU ALLOCATED:
for(int i = 0; i < r; i++)
{
    free(arr[i]);
}
free(arr);


typedef struct{
    int L;
    int w;
    point p;
} rectangle;

typedef struct{
    int x;
    int y;
} point;


(NOTE: BYTES ARE NOT CONSECUTIVE, SO ITS EASIER FOR CPU TO READ)
rectangle* r1 = malloc(sizeof(rectangle));
r1->L = 1;
r1->w = 2;
r1->p->y = 4;


rectangle r = ...
r.L = 

rectangle* r = ...
r->L *(r).L


rectangle* construct_rectangle(int L, int W, char* name)
{
    rectangle* r = malloc(sizeof(rectangle));

    if (r == NULL)
    {
        return NULL;
    }

    r->L = L;
    r->W = W;
    r->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (r->name == NULL)
    {
        free(r);
        return NULL;
    }
    strcpy(r->name, name);
    return r;
}

## destruct

void destruct_rectangle(rectangle* r)
{
    free(r->name);
    free(r);
}

rectangle* copy_rectangle(rectangle* r)
{
    return construct_rectangle(r->L, r->W, r->name);
}

rectangle* replace_rectangle(rectangle* r1, rectangle* r2)
{
    destruct_rectangle(r1);
    return copy_rectangle(r2);
}

r3 = replace_rectangle(r3,r2); // will destroy the r3, and replace with r2.
