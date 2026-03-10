# Stack Datatype

LIFO datatype

list_stack //implimenting stack using linked list

List Quese before that.

typedef struct {
    //tail is optional
    linked_list *list; //requires head == top
} list_stack;

*list_stack construct+_list_stack() {
    list_stack* stack = malloc(sizeof(list_stack));
    if (stack == NULL) return NULL;
    stack->list = construct_linked_list();
    if (queue-> == NULL) {
        free(queue);
        return NULL;
    }
}

void destruct_list_stack (*list_stack stack) {
    if (stack == NULL) return;
    destruct_linked_list(stack->list);
    free(stack);
}

//shoudl enqueue be from the back or top of the list. which to pick?
// enqueue means add a node, dequeue means to remove a node
// easiest: dequeue on the leftmost node front, and rightmost node back
// (dequeue) A -> B -> C ->D ->E ->F(enqueue)
void enqueue(*list_stack stack, int value) {
    if (stack == NULL) return;
    insert_head(stack->list,value);
}

Insert head for push, and delete_head for pop. 

void push(*list_stack stack, value) {

}

int pop(*list_stack stack) {
    if (stack == NULL || is_empty(stack->list))
    exit(EXIT_FAILURE)l

    int value
}

What to do with these linear data structures?
Palindromes (can use stack, since it lets you reverse elements of stack):
EXE: A,B,C, pushed onto stack consec: C,B,A, and then can read at head downward no problem

Parenthesis Matching: exe when closing symbol found must match most recent opening symbol of the same type:

Pseudo-code:

Repeat:
 ch1 <- read(str)
 if (ch1 == '(','{', etc)
    push(ch1);
else
    ch2 <- pop()
    if (is_empty(stack)) error!
    if (!matching(ch1,ch2))
        error
if(!is_empty(stack)) error! (empty means every opening has corresp closing)

remove outermost parenthesis:
() () -> ""
( () () ) -> () ()

output = ""
Repeat:
    ch <- read();
    if (ch == 'c')
        if (!is_empty(stack))
            output <- ch1
        push(ch1)
    else
        ch2 <- pop();
        if !(is_empty())
            output <- ch2

print(output)


Integer Partition (WILL BE ON EXAM):
a positive numer can be partitioned into teh sum of a sequence of positive integers, want to find the number of possible partitions, where order matters


4 = 1+1+1+1, or 1+2+1, or 1 + 3 ... 8 total.
solve via recursion!

f(4) = 8 = f(3) + f(2) + f(1) + 1

f(n) = f(n-1) + f(n-2) + ... + f(1) + f(0)


f(n)-f(n-1) = f(n-1)
f(n) = 2 * f(n-1)
f(n) = 2 ^ (n-1)

write code:

int f(int n) {

    if (n == 0) return 1; //termination condition
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += f(n-1);
    return total;
}

(DO IT ASCENDING)
int f(int n, int min) {

    if (n == 0) return 1; //termination condition
    int total = 0;
    for (int i = min; i <= n; i++)
        total += f(n-1, i+1);
    return total;
}



Inductive Definition

set of trees T is inductively defined as:

1: A singlular node is a tree

2: to make more complex ones, make connections between the nodes.
Rules: only 1 root node of the tree.
Root node connects to all nodes, all other nodes to not connect with each other





defined as:

1: a single root node in teh tree