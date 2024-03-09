/*
 * Data Structures: Linear Data Structures (Linked Lists)
 * Linked list is a "collection of elements" called "nodes".
 * Each node stores two items of information—an "element of the list (data)" and a "link".
 * Nodes (elements) of a linked list are not constrained to be stored in "adjacent memory locations".
 * A link is a "pointer" or an "address" that indicates explicitly the location of the "next node".
 * The "NULL" in the last node indicates that this is the "last node" in the list.
*/
#include<stdio.h>
#include<stdlib.h>

/* structure containing a data part and link part */
struct node
{
    int data;
    struct node *link;
};

void append(struct node **, int);
void copy(struct node *, struct node **);
void display(struct node *);

int main()
{
    /* Recursive Operations On Linked List
     * Program to copy one linked list into another using recursion
    */

    struct node *first, *second;
    first = second = NULL;   /* empty linked lists */

    system("clear");

    append(&first, 1);
    append(&first, 2);
    append(&first, 3);
    append(&first, 4);
    append(&first, 5);
    append(&first, 6);
    append(&first, 7);

    display(first);

    copy(first, &second);

    display(second);

    return 0;
}

/* Adds a node at the end of a linked list */
void append(struct node **q, int num)
{
    struct node *temp;
    temp = *q;

    if(*q == NULL)  /* if the list is empty, create first node */
    {
        *q = (struct node *)malloc(sizeof(struct node));
        temp = *q;
    }
    else
    {
        /* go to last node */
        while(temp->link != NULL)
            temp = temp->link;

        /* add node at the end */
        temp->link = (struct node *)malloc(sizeof(struct node));
        temp = temp->link;
    }

    /* assign data to the last node */
    temp->data = num;
    temp->link = NULL;
}

/* Copies a linked list into another */
void copy(struct node *q, struct node **s)
{
    if(q != NULL)
    {
        *s = (struct node *)malloc(sizeof(struct node));
        (*s)->data = q->data;
        (*s)->link = NULL;

        copy(q->link, &((*s)->link));
    }
}

/* Displays the contents of the linked list */
void display(struct node *q)
{
    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%d ", q->data);
        q = q->link;
    }
    printf("\n");
}
