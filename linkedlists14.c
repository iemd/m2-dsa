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

/* structure representing a node of a linked list. The node can store term of a polynomial */
struct polynode
{
    float coeff;
    int exp;
    struct polynode *link;
};

void poly_append(struct polynode **, float, int);
void display_poly(struct polynode *);
void poly_add(struct polynode *, struct polynode *, struct polynode **);

int main()
{
    /* Linked Lists And Polynomials (Addition Of Two Polynomials) */

    struct polynode *first, *second, *total;
    int i = 0;

    first = second = total = NULL;  /* empty linked lists */

    system("clear");

    poly_append(&first, 1.4f, 5);
    poly_append(&first, 1.5f, 4);
    poly_append(&first, 1.7f, 2);
    poly_append(&first, 1.8f, 1);
    poly_append(&first, 1.9f, 0);

    display_poly(first);

    poly_append(&second, 1.5f, 6);
    poly_append(&second, 2.5f, 5);
    poly_append(&second, -3.5f, 4);
    poly_append(&second, 4.5f, 3);
    poly_append(&second, 6.5f, 1);

    printf("\n\n");
    display_poly(second);

    /* draws a dashed horizontal line */
    printf("\n");
    while(i++ < 79)
        printf("-");
    printf("\n\n");

    poly_add(first, second, &total);

    display_poly(total);    /* displays the resultant polynomial */
    printf("\n\n");

    return 0;
}

/* Adds a term to a polynomial */
void poly_append(struct polynode **q, float x, int y)
{
    struct polynode *temp;
    temp = *q;

    /* creates a new node if the list is empty */
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
    printf("\b\b ");   /* erases the last colon */
}

/* Adds two polynomials */
void poly_add(struct polynode *x, struct polynode *y, struct polynode **s)
{
    struct polynode *z;

    /* if both linked lists are empty */
    if(x == NULL && y == NULL)
        return;

    /* traverse till one of the list ends */
    while(x != NULL && y != NULL)
    {
        /* create a new node if the list is empty */
        if(*s == NULL)
        {
            *s = (struct polynode *)malloc(sizeof(struct polynode));
            z = *s;
        }
        /* create new nodes at intermediate stages */
        else
        {
            z->link = (struct polynode *)malloc(sizeof(struct polynode));
            z = z->link;
        }

        /* store a term of the larger degree polynomial */
        if(x->exp < y->exp)
        {
            z->coeff = y->coeff;
            z->exp = y->exp;
            y = y->link;    /* go to the next node */
        }
        else
        {
            if(x->exp > y->exp)
            {
                z->coeff = x->coeff;
                z->exp = x->exp;
                x = x->link;    /* go to the next node */
            }
            else
            {
                /* add the coefficients, when exponents are equal */
                if(x->exp == y->exp)
                {
                    /* assigning the added coefficient */
                    z->coeff = x->coeff + y->coeff;
                    z->exp = x->exp;
                    /* go to the next node */
                    x = x->link;
                    y = y->link;
                }
            }
        }
    }

    /* assign remaining terms of the first polynomial to the result */
    while(x != NULL)
    {
        if(*s == NULL)
        {
            *s = (struct polynode *)malloc(sizeof(struct polynode));
            z = *s;
        }
        else
        {
            z->link = (struct polynode *)malloc(sizeof(struct polynode));
            z = z->link;
        }

        /* assign coefficient and exponent */
        z->coeff = x->coeff;
        z->exp = x->exp;
        x = x->link;    /* go to the next node */
    }

    /* assign remaining terms of the second polynomial to the result */
    while(y != NULL)
    {
        if(*s == NULL)
        {
            *s = (struct polynode *)malloc(sizeof(struct polynode));
            z = *s;
        }
        else
        {
            z->link = (struct polynode *)malloc(sizeof(struct polynode));
            z = z->link;
        }

        /* assign coefficient and exponent */
        z->coeff = y->coeff;
        z->exp = y->exp;
        y = y->link;    /* go to the next node */
    }

    z->link = NULL; /* assign NULL at end of resulting linked list */
}
