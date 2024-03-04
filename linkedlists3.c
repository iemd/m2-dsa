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

void addatbeg(struct node **, int);
void reverse(struct node **);
void display(struct node *);
int count(struct node *);

int main()
{
    /* Reversing The Links */

    struct node *p;
    p = NULL;   /* empty linked list */

    addatbeg(&p, 7);
    addatbeg(&p, 43);
    addatbeg(&p, 17);
    addatbeg(&p, 3);
    addatbeg(&p, 23);
    addatbeg(&p, 5);

    system("clear");

    display(p);
    printf("No. of elements in the Linked List=%d\n\n", count(p));

    reverse(&p);

    display(p);
    printf("No. of elements in the Linked List=%d\n\n", count(p));

    return 0;
}

/* Adds a new node at the beginning of the linked list */
void addatbeg(struct node **q, int num)
{
    struct node *temp;

    /* add new node */
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = num;
    temp->link = *q;
    *q = temp;
}

void reverse(struct node **x)
{
    struct node *q, *r, *s;

    q = *x;
    r = NULL;

    /* traverse the entire linked list */
    while(q != NULL)
    {
        s = r;
        r = q;
        q = q->link;
        r->link = s;
    }

    *x = r;
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
