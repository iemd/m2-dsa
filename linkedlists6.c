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
} *start, *visit;

void getdata();
void append(struct node **q, int num);

void displaylist();

void selection_sort();
void bubble_sort();

int main()
{
    /* Sorting A Linked List (by readjusting the link part of node) */

    system("clear");

    printf("*****Selection Sorting*****\n\n");

    getdata();
    printf("Linked List Before Sorting:\n");
    displaylist();

    selection_sort();
    printf("Linked List After Selection Sorting:\n");
    displaylist();

    printf("\n*****Bubble Sorting*****\n\n");

    getdata();
    printf("Linked List Before Sorting:\n");
    displaylist();

    bubble_sort();
    printf("Linked List After Bubble Sorting:\n");
    displaylist();

    return 0;
}

void getdata()
{
    int val;
    char ch;
    struct node *newnode;
    int dh;

    //system("clear");

    newnode = NULL;

    do
    {
        printf("Enter a value:");
        scanf("%d", &val);

        append(&newnode, val);

        printf("Any More Nodes(Y/N):");
        //fflush(stdin);
        while((dh=getchar()) != '\n')
            ;
        ch = getchar();
        printf("\n");

    }while(ch=='y' || ch=='Y');

    start = newnode;
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

/* Displays the contents of the linked list */
void displaylist()
{
    visit = start;

    /* traverse the entire linked list */
    while(visit != NULL)
    {
        printf("%d ", visit->data);
        visit = visit->link;
    }
    printf("\n");
}

void selection_sort()
{
    struct node *p, *q, *r, *s, *temp;

    p = r = start;
    while(p->link != NULL)
    {
        s = q = p->link;
        while(q != NULL)
        {
            if(p->data > q->data)
            {
                if(p->link == q)    /* Adjacent Nodes */
                {
                    if(p == start)
                    {
                        p->link = q->link;
                        q->link = p;

                        temp = p;
                        p = q;
                        q = temp;

                        start = p;
                        r = p;
                        s = q;
                        q = q->link;
                    }
                    else
                    {
                        p->link = q->link;
                        q->link = p;
                        r->link = q;

                        temp = p;
                        p = q;
                        q = temp;

                        s = q;
                        q = q->link;
                    }
                }
                else
                {
                    if(p == start)
                    {
                        temp = q->link;
                        q->link = p->link;
                        p->link = temp;

                        s->link = p;
                        temp = p;
                        p = q;
                        q = temp;

                        s = q;
                        q = q->link;
                        start = p;
                    }
                    else
                    {
                        temp = q->link;
                        q->link = p->link;
                        p->link = temp;
                        r->link = q;
                        s->link = p;

                        temp = p;
                        p = q;
                        q = temp;

                        s = q;
                        q = q->link;
                    }
                }
            }
            else
            {
                s = q;
                q = q->link;
            }
        }
        r = p;
        p = p->link;
    }
}

void bubble_sort()
{
    struct node *p, *q, *r, *s, *temp;
    s = NULL;

    /* r precedes p and s points to the node up to which comparisons are to be made */
    while(s != start->link)
    {
        r = p = start;
        q = p->link;

        while(p != s)
        {
            if(p->data > q->data)
            {
                if(p == start)
                {
                    temp = q->link;
                    q->link = p;
                    p->link = temp;

                    start = q;
                    r = q;
                }
                else
                {
                    temp = q->link;
                    q->link = p;
                    p->link = temp;

                    r->link = q;
                    r = q;
                }
            }
            else
            {
                r = p;
                p = p->link;
            }
            q = p->link;
            if(q == s)
                s = p;
        }
    }
}
