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

void addcirq(struct node **, struct node **, int);
int delcirq(struct node **, struct node **);
void cirq_display(struct node *);

int main()
{
    /* A Queue as a Circular Linked List */

    struct node *front, *rear;

    front = rear = NULL;

    system("clear");

    addcirq(&front, &rear, 10);
    addcirq(&front, &rear, 17);
    addcirq(&front, &rear, 18);
    addcirq(&front, &rear, 5);
    addcirq(&front, &rear, 30);
    addcirq(&front, &rear, 15);

    printf("Before deletion:\n");
    cirq_display(front);

    delcirq(&front, &rear);
    delcirq(&front, &rear);
    delcirq(&front, &rear);

    printf("After deletion:\n");
    cirq_display(front);

    return 0;
}

/* Adds a new element at the end of queue */
void addcirq(struct node **f, struct node **r, int item)
{
    struct node *q;

    /* create new node */
    q = (struct node *)malloc(sizeof(struct node));
    q->data = item;
    
    /* if the queue is empty */
    if(*f == NULL)
        *f = q;
    else
        (*r)->link = q;

    *r = q;
    (*r)->link = *f;
}

/* Removes an element from front of queue */
int delcirq(struct node **f, struct node **r)
{
    struct node *q;
    int item;

    /* if queue is empty */
    if(*f == NULL)
        printf("queue is empty\n");
    else
    {
        if(*f == *r)
        {
            item = (*f)->data;
            free(*f);
            *f = NULL;
            *r = NULL;
        }
        else
        {
            /* delete the node */
            q = *f;
            item = q->data;
            *f = (*f)->link;
            (*r)->link = *f;
            free(q);            
        }
        return item;
    }
    //return NULL;
}

/* Displays whole of the queue */
void cirq_display(struct node *f)
{
    struct node *q = f, *p = NULL;

    /* traverse the entire linked list */
    while(q != p)
    {
        printf("%d ", q->data);

        q = q->link;
        p = f;
    }
    printf("\n");
}
