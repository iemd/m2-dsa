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

/* structure representing a node of a linked list. The node can store a term of a polynomial */
struct polynode
{
    float coeff;
    int exp;
    struct polynode *link;
};

void poly_append(struct polynode **, float, int);
void display_poly(struct polynode *);
void poly_multiply(struct polynode *, struct polynode *, struct polynode **);
void padd(float, int, struct polynode **);

int main()
{
    /* Linked Lists And Polynomials (Multiplication Of Two Polynomials) */

    struct polynode *first, *second, *mult;
    int i = 1;

    first = second = mult = NULL;  /* empty linked lists */

    system("clear");

    poly_append(&first, 3, 5);
    poly_append(&first, 2, 4);
    poly_append(&first, 1, 2);

    display_poly(first);

    poly_append(&second, 1, 6);
    poly_append(&second, 2, 5);
    poly_append(&second, 3, 4);

    printf("\n\n");
    display_poly(second);

    /* draws a dashed horizontal line */
    printf("\n");
    while(i++ < 79)
        printf("-");
    printf("\n\n");

    poly_multiply(first, second, &mult);

    display_poly(mult);
    printf("\n\n");

    return 0;
}

/* Adds a term to a polynomial */
void poly_append(struct polynode **q, float x, int y)
{
    struct polynode *temp;
    temp = *q;

    /* create a new node if the list is empty */
    if(*q == NULL)
    {
        *q = (struct polynode *)malloc(sizeof(struct polynode));
        temp = *q;
    }
    else
    {
        /* traverse the entire linked list */
        while(temp->link != NULL)
            temp = temp->link;

        /* create new nodes at intermediate stages */
        temp->link = (struct polynode *)malloc(sizeof(struct polynode));
        temp = temp->link;
    }

    /* assign coefficient and exponent */
    temp->coeff = x;
    temp->exp = y;
    temp->link = NULL;
}

/* Displays the contents of linked list representing a polynomial */
void display_poly(struct polynode *q)
{
    /* traverse till the end of the linked list */
    while(q != NULL)
    {
        printf("%.1fx^%d : ", q->coeff, q->exp);
        q = q->link;
    }
    printf("\b\b ");   /* erases the last colon(:) */
}

/* Multiplies the two polynomials */
void poly_multiply(struct polynode *x, struct polynode *y, struct polynode **m)
{
    struct polynode *y1;
    float coeff1;
    int exp1;

    y1 = y; /* point to the starting of the second linked list */

    if(x == NULL && y == NULL)
        return;

    /* if one of the list is empty */
    if(x == NULL)
        *m = y;
    else
    {
        if(y == NULL)
            *m = x;
        else    /* if both linked lists exist */
        {
            /* for each term of the first list */
            while(x != NULL)
            {
                /* multiply each term of the second linked list with a term of the first linked list */
                while(y != NULL)
                {
                    coeff1 = x->coeff * y->coeff;
                    exp1 = x->exp + y->exp;
                    y = y->link;

                    /* add the new term to the resultant polynomial */
                    padd(coeff1, exp1, m);
                }
                y = y1; /* reposition the pointer to the starting of the second linked list */
                x = x->link;    /* go to the next node */
            }
        }
    }    
}

/* Adds a term to the polynomial in the descending order of the exponent */
void padd(float c, int e, struct polynode **s)
{
    struct polynode *r = NULL, *temp = *s;

    /* if list is empty or if the node is to be inserted before the first node */
    if(*s == NULL || e > (*s)->exp)
    {
        *s = r = (struct polynode *)malloc(sizeof(struct polynode));
        (*s)->coeff = c;
        (*s)->exp = e;
        (*s)->link = temp;
    }
    else
    {
        /* traverse the entire linked list to search the position to insert a new node */
        while(temp != NULL)
        {
            if(temp->exp == e)
            {
                temp->coeff += c;
                return;
            }
            if(temp->exp > e && (temp->link == NULL || temp->link->exp < e))
            {
                r = (struct polynode *)malloc(sizeof(struct polynode));
                r->coeff = c;
                r->exp = e;
                r->link = temp->link;
                temp->link = r;
                return;
            }
            temp = temp->link;  /* go to next node */
        }
        r->link = NULL;
        temp->link = r;
    }
}
