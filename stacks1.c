/*
 * Data Structures: Linear Data Structures (Stacks)
 * The linear data structure such as an "array" and a "linked list" allows us to insert and delete an
   element at "any place" in the list, either "at the beginning" or "at the end" or even "in the middle".
 * However, sometimes it is required to permit the addition or deletion of elements "only at one end",
   that is either "at the beginning" or "at the end".
 * Stack and Queue are two types of data structures in which the addition or deletion of an element is
   done "at end", rather than "in the middle".
 * A Stack is a data structure in which "addition of new element" or "deletion of an existing element"
   always takes place "at the same end".
 * This end is often known as "top" of stack.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct stack
{
    int arr[MAX];
    int top;
};

void initstack(struct stack *);
void push(struct stack *, int item);
int pop(struct stack *);

int main()
{
    /* Operations On Stack (Stack As An Array) */

    struct stack s;
    int i;

    system("clear");

    initstack(&s);

    push(&s, 11);
    push(&s, 23);
    push(&s, -8);
    push(&s, 16);
    push(&s, 27);
    push(&s, 14);
    push(&s, 20);
    push(&s, 39);
    push(&s, 2);
    push(&s, 15);
    push(&s, 7);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);
    
    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    return 0;
}

/* Initializes the stack */
void initstack(struct stack *s)
{
    s->top = -1;
}

/* Adds an element to the stack */
void push(struct stack *s, int item)
{
    if(s->top == MAX-1)
    {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->arr[s->top] = item;
}

/* Removes an element from the stack */
int pop(struct stack *s)
{
    int data;
    if(s->top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    data = s->arr[s->top];
    s->top--;

    return data;
}
