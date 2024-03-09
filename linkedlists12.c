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

struct node
{
    int data;
    struct node *link;
};

void addatend(struct node **, int);
void display(struct node *);

int main()
{
    /* Recursive Operations On Linked List
     * Program to add a new node at the end of linked list using recursion
    */

    struct node *p;

    p = NULL;

    system("clear");

    addatend(&p, 1);
    addatend(&p, 2);
    addatend(&p, 3);
    addatend(&p, 4);
    addatend(&p, 5);
    addatend(&p, 6);
    addatend(&p, 7);
    addatend(&p, 8);
    addatend(&p, 9);
    addatend(&p, 10);

    display(p);

    return 0;
}

/* Adds a new node at the end of the linked list */
void addatend(struct node **s, int num)
{
    if(*s == NULL)
    {
        *s = (struct node *)malloc(sizeof(struct node));
        (*s)->data = num;
        (*s)->link = NULL;
    }
    else
        addatend(&((*s)->link), num);
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
