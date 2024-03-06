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
void append(struct node **, int);

void displaylist();
int count(struct node *);

void selection_sort(int);
void bubble_sort(int);

int main()
{
    /* Sorting A Linked List (by exchanging the data part of node) */

    int n;

    system("clear");

    printf("*****Selection Sorting*****\n\n");

    getdata();
    printf("Linked list Before Sorting:\n");
    displaylist();

    n = count(start);

    selection_sort(n);
    printf("Linked list After Selection Sorting:\n");
    displaylist();

    printf("\n*****Bubble Sorting*****\n\n");

    getdata();
    printf("Linked list Before Sorting:\n");
    displaylist();

    n = count(start);

    bubble_sort(n);
    printf("Linked list After Bubble Sorting:\n");
    displaylist();

    return 0;
}

void getdata()
{
    int val;
    char ch;
    struct node *new;
    int dh;

    //system("clear");

    new = NULL;

    do
    {
        printf("Enter a value:");
        scanf("%d", &val);

        append(&new, val);

        printf("Any More Nodes(Y/N):");
        //fflush(stdin);
        while((dh=getchar()) != '\n')
            ;
        ch = getchar();
        printf("\n");

    }while(ch=='y' || ch=='Y');

    start = new;
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

void selection_sort(int n)
{
    int i, j, temp;
    struct node *p, *q;

    p = start;
    for(i=0; i<n-1; i++)
    {
        q = p->link;

        for(j=i+1; j<n; j++)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->link;
        }
        p = p->link;
    }
}

void bubble_sort(int n)
{
    int i, j, k, temp;
    struct node *p, *q;

    k = n;
    for(i=0; i<n-1; i++,k--)
    {
        p = start;
        q = p->link;

        for(j=1; j<k; j++)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            p = p->link;
            q = q->link;
        }
    }
}
