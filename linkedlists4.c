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
void merge(struct node *, struct node *, struct node **);

int main()
{
    /* Merging Of Linked Lists */

    struct node *first, *second, *third;
    first = second = third = NULL;  /* empty linked lists */

    system("clear");

    add(&first, 9);
    add(&first, 12);
    add(&first, 14);
    add(&first, 17);
    add(&first, 35);
    add(&first, 61);
    add(&first, 79);

    printf("First linked list:\n");
    display(first);
    printf("No. of elements in Linked List:%d\n\n", count(first));

    add(&second, 12);
    add(&second, 17);
    add(&second, 24);
    add(&second, 36);
    add(&second, 59);
    add(&second, 64);
    add(&second, 87);

    printf("Second linked list:\n");
    display(second);
    printf("No. of elements in Linked List:%d\n\n", count(second));

    merge(first, second, &third);

    printf("The merged list:\n");
    display(third);
    printf("No. of elements in Linked List:%d\n\n", count(third));

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

        r->link = NULL;
        temp->link = r;
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

/* Merges the two linked lists, restricting the common elements to occur only once in the final list */
void merge(struct node *p, struct node *q, struct node **s)
{
    struct node *z;

    z = NULL;

    /* if both lists are empty */
    if(p == NULL && q == NULL)
        return;

    /* traverse both linked lists till the end, if end of any one list is reached loop is terminated */
    while(p != NULL && q != NULL)
    {
        /* if node being added is the first node */
        if(*s == NULL)
        {
            *s = (struct node *)malloc(sizeof(struct node));
            z = *s;
        }
        else
        {
            z->link = (struct node *)malloc(sizeof(struct node));
            z = z->link;
        }

        if(p->data < q->data)
        {
            z->data = p->data;
            p = p->link;
        }
        else
        {
            if(q->data < p->data)
            {
                z->data = q->data;
                q = q->link;
            }
            else
            {
                if(p->data == q->data)
                {
                    z->data = q->data;
                    p = p->link;
                    q = q->link;
                }
            }
        }
    }

    /* if end of first list has not been reached */
    while(p != NULL)
    {
        z->link = (struct node *)malloc(sizeof(struct node));
        z = z->link;
        z->data = p->data;
        p = p->link;
    }

    /* if end of second list has not been reached */
    while(q != NULL)
    {
        z->link = (struct node *)malloc(sizeof(struct node));
        z = z->link;
        z->data = q->data;
        q = q->link;
    }

    z->link = NULL;
}
