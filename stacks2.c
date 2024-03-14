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

/* structure containing data part and link part */
struct node
{
    int data;
    struct node *link;
};

void push(struct node **, int);
int pop(struct node **);
void delstack(struct node **);

int main()
{
    /* Operations On Stack (Stack As A Linked List) */

    struct node *s = NULL;
    int i;

    system("clear");

    push(&s, 14);
    push(&s, -3);
    push(&s, 18);
    push(&s, 29);
    push(&s, 31);
    push(&s, 16);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    i = pop(&s);
    if(i != -1)
        printf("Item popped:%d\n", i);

    delstack(&s);

    return 0;
}

/* Adds a new node to the stack as linked list */
void push(struct node **top, int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
        printf("Stack is full.\n");

    temp->data = item;
    temp->link = *top;
    *top = temp;
}

/* Pops an element from the stack */
int pop(struct node **top)
{
    struct node *temp;
    int item;

    if(*top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    temp = *top;
    item = temp->data;
    *top = (*top)->link;

    free(temp);
    return item;
}

/* Deallocates memory */
void delstack(struct node **top)
{
    struct node *temp;

    if(*top == NULL)
        return;

    while(*top != NULL)
    {
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
}
