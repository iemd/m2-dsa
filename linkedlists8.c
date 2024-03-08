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
void concat(struct node **, struct node **);

void display(struct node *);
int count(struct node *);

struct node * erase(struct node *);

int main()
{
    /* A Few More Operations */

    struct node *first, *second;

    first = second = NULL;  /* empty linked list */

    system("clear");

    append(&first, 1);
    append(&first, 2);
    append(&first, 3);
    append(&first, 4);

    printf("First List:\n");
    display(first);
    printf("No. of elements in the first Linked List=%d\n\n", count(first));

    append(&second, 5);
    append(&second, 6);
    append(&second, 7);
    append(&second, 8);

    printf("Second List:\n");
    display(second);
    printf("No. of elements in the second Linked List=%d\n\n", count(second));

    /* the result obtained after concatenation is in the first list */
    concat(&first, &second);

    printf("Concatenated List:\n");
    display(first);

    printf("No. of elements in Linked List before erasing=%d\n", count(first));

    first = erase(first);
    printf("No. of elements in Linked List after erasing=%d\n", count(first));

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

/* Concatenates two linked lists */
void concat(struct node **p, struct node **q)
{
    struct node *temp;

    /* if the first linked list is empty */
    if(*p == NULL)
        *p = *q;
    else
    {
        /* if both linked lists are non-empty */
        if(*q != NULL)
        {
            temp = *p;  /* points to the starting of the first list */

            /* traverse the entire first linked list */
            while(temp->link != NULL)
                temp = temp->link;

            temp->link = *q;    /*concatenate the second list after the first */
        }
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

/* Counts the number of nodes present in the linked list */
int count(struct node *q)
{
    int c = 0;

    /* traverse the entire linked list */
    while(q != NULL)
    {
        q = q->link;
        c++;
    }

    return c;
}

/* Erases all the nodes from a linked list */
struct node * erase(struct node *q)
{
    struct node *temp;

    /* traverse till the end erasing each node */
    while(q != NULL)
    {
        temp = q;
        q = q->link;
        free(temp); /* free the memory occupied by the node */
    }

    return NULL;
}
