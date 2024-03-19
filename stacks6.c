/*
 * Data Structures: Linear Data Structures (Stacks)
 * The linear data structure such as an "array" and a "linked list" allows us to insert and delete an
   element at "any place" in the list, either "at the beginning" or "at the end" or even "in the middle".
 * However, sometimes it is required to permit the addition or deletion of elements "only at one end",
   that is either "at the beginning" or "at the end".
 * Stack and Queue are two types of data structures in which the addition or deletion of an element is
   done "at end", rather than "in the middle".
 * A Stack is a data structure in which "addition of new element" or "deletion of an existing element"
   always takes place "at the same end".
 * This end is often known as "top" of stack.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct postfix
{
    char stack[MAX][MAX], target[MAX];
    char temp1[2], temp2[2];
    char str1[MAX], str2[MAX], str3[MAX];
    int i, top;
};

void initpostfix(struct postfix *);
void setexpr(struct postfix *, char *);

void push(struct postfix *, char *);
void pop(struct postfix *, char *);

void convert(struct postfix *);
void show(struct postfix);

int main()
{
    /* Applications Of Stacks (Postfix To Infix Conversion) */

    struct postfix q;
    char expr[MAX];

    system("clear");

    initpostfix(&q);

    printf("Enter an expression in postfix form:\n");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    setexpr(&q, expr);
    convert(&q);

    printf("The infix expression is:\n");
    show(q);

    return 0;
}

/* Initializes structure elements */
void initpostfix(struct postfix *p)
{
    p->i = 0;
    p->top = -1;
    strcpy(p->target, "");
}

/* Copies given expr. to target string */
void setexpr(struct postfix *p, char *c)
{
    strcpy(p->target, c);
}

/* Adds an expr. to the stack */
void push(struct postfix *p, char *str)
{
    if(p->top == MAX-1)
        printf("Stack is full.\n");
    else
    {
        p->top++;
        strcpy(p->stack[p->top], str);
    }
}

/* Pops an expr. from the stack */
void pop(struct postfix *p, char *a)
{
    if(p->top == -1)
    {
        printf("Stack is empty.\n");
        //return NULL;
    }
    else
    {
        strcpy(a, p->stack[p->top]);
        p->top--;
    }
}

/* Converts given expr. to infix form */
void convert(struct postfix *p)
{
    while(p->target[p->i] != '\0')
    {
        /* skip whitespace, if any */
        if(p->target[p->i] == ' ')
            p->i++;
        if(p->target[p->i]=='%' || p->target[p->i]=='*' || p->target[p->i]=='-' ||
            p->target[p->i]=='+' || p->target[p->i]=='/' || p->target[p->i]=='$')
        {
            pop(p, p->str2);
            pop(p, p->str3);

            p->temp1[0] = p->target[p->i];
            p->temp1[1] = '\0';

            strcpy(p->str1, p->str3);

            strcat(p->str1, p->temp1);
            strcat(p->str1, p->str2);

            push(p, p->str1);
        }
        else
        {
            p->temp1[0] = p->target[p->i];
            p->temp1[1] = '\0';

            strcpy(p->temp2, p->temp1);

            push(p, p->temp2);
        }
        p->i++;
    }
}

/* Displays the expression */
void show(struct postfix p)
{
    char *t;
    t = p.stack[0];
    while(*t)
    {
        printf("%c", *t);
        t++;
    }
    printf("\n");
}
