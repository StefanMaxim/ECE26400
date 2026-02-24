# Recursion

void f() 
{
    f(); //recursive call
}

Problem: current program creates infinite stack frames, which leads to **Stack Overflow**

Solution; Use a base case to stop the recursion

int f(int n)
{
    if (n < 10)
        return (10*n) +n
    else
    {
        int a = f(n / 10);
        int b = f(n % 10);
        return (100 * a) + b
    }
}

f(348); //DRAW THE STACK!
f(348) evaluates to a value, but to show it we will use another expression, namely the arabic numeral 334488

this is a function call expression, an expression evaluates to a value.
remember: type is a class of values, values are a conceptual idea
expressions are ways to express the idea:

idea: (the number 1)
expression: 1, one, 100-99, 100/100, 

each box has values, and each of then are equal to a stack call


## functional exersize

write a RECURSIVE function that prints n stars:

void f(int n)
{

}

**APPROACH**
original problem: f(n) -> *** ... * (n times)

sub-problem: consider case f(n-1), a subproblem -> *** .. * (n-1 times)

How to connect them:
f(n), just do f(n-1) and then print out another star

void f()
{
    f(n-1);
    printf("*");
}

Problem: we are missing termination condition
since it will eventually reach 0, we do not print out anything.

void f()
{
    if (n == 0)
    {
        return;
    }
    else
    {
    f(n-1);
    printf();
    (implicit functional return here)
    }
}


Problem: print the first n integers starting with 1 in sequential order, separated by commas.
f(5) -> 1 2 3 4 5

Origional problem: f(n) -> 1,2,3,4,...,n
Subproblem: f(n-1 -> 1,2,3,4,...,n-1)

Relationship:
f(n) first f(n-1) then print ",n"


void f()
{
    if (n == 1)
    {
        printf("1");
    }
    else
    {
    f(n-1);
    printf(",%d",n);
    }
}

Problem: recursive function that prints a string in reverse.

void f(char* x)
{

}

x5 -> "abcde\n"
f(x5) -> "edcba\n"

x4 -> "abcd\n"
f(x4) -> "dcba\n"

Thus, lets first print out e, then envoke f() without the last character

void f(char* x)
{
    if (x[0] = '\0')
    {
        return;
    }
    int length = strlen(x);
    char last = x[len-1];
    x[len-1] = NULL;
    printf("%c",last);
    f(x);
}

INSTEAD: remove the first character to make it easier because its index is fixed:

a, b, c, d, e, \0
&x[1] is b,c,d,e,\0

(REVIEW THIS!)
void f(char* x)
{
    if (x[0] == '\0')
    {
        return;
    }
    f(&x[1]);
    print("%c",x[0]);
}


Problem: factorial
Problem fibonacci numbers

fib(0) = 0;
fib(1) = 1;
fib(n) = fib(n-1) + fib(n-2); (n >= 2);

int fib(n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}


## Towers of Hanoi:
(LOCK IN):
**CRITICAL**

3 pegs, rings of various size, increasing on one peg
move to another peg without having a larger peg atop a smaller one
(typically left peg to right peg)

void hanoi(int n, char x, char y, char z) //L, M, R move n disks from x to z using y as indermediary
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %n", x,z); //must be disk 1 bc only one disk must be smallest
        return;
    }
    hanoi(n-1,x,z,y); //move n-1 from peg L to peg M using peg R as intermediary
    printf("move disk %d from %c to %c\n", n, x, z); // move peg n from L to R
    hanoi(n-1,y,x,z); // move n-1 disks from M to R, using L as intermediary

}

point of confusion: x is not allways L! just at the beginning it is. 
after the first envoke it changes, 