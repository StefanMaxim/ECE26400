# Lecture 4

## Pointer

A pointer is a **variable**, whose tupe is the tpe of the value at the address followed by \*
**Pointer vs Pointer variable**

EXE:
```c
int x = 1;
int* p = &x
```

x |    1     |
p |     &x    |
q |      &p     |

printf("%d",x); printf("%d",*p) //print out the value of x

printf("%p",&x); printf("%p",p); //both print out the address of x

printf("%p",p); //print the value of p

printf("%p",&p); //print the address of p


Thus:
&p is address of p, lets store it in q = &p
what is the type of q?
int**, ie a pointer to a pointer of type int. (since pointer is * and the type of the thing it is pointing to)

//print out value of x:

printf("%d",x);, printf("%d"*p), print("%d",**q);

//print address of x:

printf("%p",&x);, printf("%p",p); printf("%p",*q);


```c

int* p = 100; (NONSENSE, 100 not an address) 
> **NOTE** users cannot specify which address to store stuff at in memory, at least not in c

char c;
&c = 10; //cannot do this either

p = &c; //can do this, but will return an error (specifically because int size is different)
        //here, using p you will read 4 bytes, starting at the c pointer and then the next 3 bytes.

```


how to swap variables:

int main() {
    int a = 1;
    int b = 2;

    a=b;
    b=a; //wrong, use a temp
}

also cannot do f(int a , int b) to swap them, as the variables are removes once stack frame popped when returning
to calling function

instead, do f(&a, &b), and swap via pointers, as pointers can dereference across stack frames
(ie write to locations in other frames, as all within the stack memory )

frame       symbol              address     value
myswap      temp                203         2
            q                   202         101
            p                   201         100
            return address      200         line 46

main        b                   101         6,2
            a                   100         2,6

Pointer of Array:
int arr[3] = {100,200,300};

arr is of type int[3], but decays to a pointer to the first element when passed as an argument.

int* p = arr; //here, it will decay so arr = &arr[0]

printf("%d",arr[0]);
printf("%d",*arr);
printf("%d",*(&arr[0])) //can also do *p


for (int i = 0; i < 3; i++)
{
    printf("%d", arr[i]); can also do *(arr+i), where the plus 1 jumps by the number of bytes of teh tyep that address 
    points to.
}

&arr[0] is first address, aka arr
&arr[1] is the second address, aka arr+1 since addition is overridded when adding to a address, so ti willactually call
(char*)arr + i * sizeof(*arr) //IMPORTANT



Recap of struct:

void f (rectamngle* r1) 
{
    r1->L = 3;
    r1->w = 4; //not r1.L or r1.w, that is not used for pointers. 

    rectangle* r2 = r1;
    (*r2).L = 5;
    (*r2).w = 6; //this also changes the r1 in the main
}

r1->L == (*r1).L (since its type rectangle, when you do r1 + 1, it will move to the end)



int main()
{
    rectangle r1;
    r1.L = 1;
    r1.w = 2;
    f(&r1);
    //note, r1 stays the same since passed by value, so what to do? use pointers
}


array of structs:
rectangle arr[100];

for(int i = 0; i < 100; i++>)
{
    arr[i].L = i+1;
    arr[i].w = i+2;
}

NOTE: suppose you cannot do arr[i].L or arr[i].w, hwo to do via pointers?

first, jump by rectangles in memory via +i and within each, jump by 4 bytes

for()
{
    rectangle* p_rec = arr+i //since decays to address of first element
    int* p_att = (int*) p_rec; //this was what i was thinking by casting it to a void pointer
    (can also do &(p_rec->L)!!!) (PREFERRED WHEN THE ATTRIBUTES ARE DIFFERENT)
    for (int j = 0; j < 2; j++)
    {
        printf("%d"; *(p_attr + j))
    }
    printf("%n");
}

size of a pointer to char?
8 bytes.(64 bit os)
size of pointer to a short?
8 bytes
... (ALL ADDRESSES are 8 bytes)

