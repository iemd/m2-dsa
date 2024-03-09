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
int length(struct node *);

int main()
{
    /* Recursive Operations On Linked List
     * Program to find the number of nodes in the linked list using recursion
    */

    struct node *p;
    p = NULL;   /* empty linked list */

    system("clear");

    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    append(&p, 5);

    printf("Length of linked list=%d\n", length(p));

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

/* Counts the number of nodes in a linked list */
int length(struct node *q)
{
    static int l;

    /* if list is empty or if NULL is encountered */
    if(q == NULL)
        return(0);
    else
    {
        /* go to next node */
        l = 1 + length(q->link);
        return(l);
    }
}
