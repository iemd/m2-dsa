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

void append(struct node **, int);
int compare(struct node *, struct node *);

int main()
{
    /* Recursive Operations On Linked List
     * Program to compare two linked lists using recursion
    */

    struct node *first, *second;
    first = second = NULL;   /* empty linked lists */

    system("clear");

    append(&first, 1);
    append(&first, 2);
    append(&first, 3);

    append(&second, 1);
    append(&second, 2);
    append(&second, 3);

    if(compare(first, second))
        printf("Both linked lists are EQUAL\n");
    else
        printf("Linked lists are DIFFERENT\n");

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

/* Compares 2 linked lists and returns 1 if linked lists are equal and 0 if unequal */
int compare(struct node *q, struct node *r)
{
    static int flag;

    if((q == NULL) && (r == NULL))
        flag = 1;
    else
    {
        if((q == NULL) || (r == NULL))
            flag = 0;

        if(q->data != r->data)
            flag = 0;
        else
            compare(q->link, r->link);
    }
    return(flag);
}
