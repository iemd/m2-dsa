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

void add(struct node **, int);
void display(struct node *);
int count(struct node *);

int main()
{
    /* Ascending Order Linked List */

    struct node *p;
    p = NULL;   /* empty linked list */

    system("clear");

    add(&p, 5);
    add(&p, 1);
    add(&p, 6);
    add(&p, 4);
    add(&p, 7);

    display(p);
    printf("No. of elements in Linked List=%d\n\n", count(p));

    return 0;
}

/* Adds node to an ascending order linked list */
void add(struct node **q, int num)
{
    struct node *r, *temp = *q;

    r = (struct node *)malloc(sizeof(struct node));

    r->data = num;

    /* if list is empty or if new node is to be inserted before the first node */
    if(*q == NULL || (*q)->data > num)
    {
        *q = r;
        (*q)->link = temp;
    }
    else
    {
        /* traverse the entire linked list to search the position to insert the new node */
        while(temp != NULL)
        {
            if(temp->data <= num && (temp->link == NULL || temp->link->data > num))
            {
                r->link = temp->link;
                temp->link = r;
                
                return;
            }
            temp = temp->link;  /* go to the next node */
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
