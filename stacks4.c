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
#include<ctype.h>

#define MAX 50

struct infix
{
    char target[MAX];
    char stack[MAX];
    char *s, *t;
    int top;
};

void initinfix(struct infix *);
void setexpr(struct infix *, char *);

void push(struct infix *, char);
char pop(struct infix *);

void convert(struct infix *);
int priority(char);
void show(struct infix);

int main()
{
    /* Applications Of Stacks (Infix To Postfix Conversion) */

    struct infix p;
    char expr[MAX];

    initinfix(&p);

    system("clear");

    printf("Enter an expression in infix form:\n");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    setexpr(&p, expr);
    convert(&p);    

    printf("The postfix expression is:\n");

    show(p);

    return 0;
}

/* Initializes structure elements */
void initinfix(struct infix *p)
{
    p->top = -1;
    strcpy(p->target, "");
    strcpy(p->stack, "");
    p->t = p->target;
    p->s = "";
}

/* Sets s to point to given expr. */
void setexpr(struct infix *p, char *str)
{
    p->s = str;
}

/* Adds an operator to the stack */
void push(struct infix *p, char c)
{
    if(p->top == MAX)
        printf("Stack is full.\n");
    else
    {
        p->top++;
        p->stack[p->top] = c;
    }
}

/* Pops an operator from the stack */
char pop(struct infix *p)
{
    if(p->top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        char item = p->stack[p->top];
        p->top--;
        return item;
    }
}

/* Converts the given expr. from infix to postfix form */
void convert(struct infix *p)
{
    char opr;

    while(*(p->s))
    {
        if(*(p->s)==' ' || *(p->s)=='\t')
        {
            p->s++;
            continue;
        }
        if(isdigit(*(p->s)) || isalpha(*(p->s)))
        {
            while(isdigit(*(p->s)) || isalpha(*(p->s)))
            {
                *(p->t) = *(p->s);
                p->s++;
                p->t++;
            }
        }
        if(*(p->s)=='(')
        {
            push(p, *(p->s));
            p->s++;
        }
        if(*(p->s)=='*' || *(p->s)=='+' || *(p->s)=='/' || *(p->s)=='%' || *(p->s)=='-' || *(p->s)=='$')
        {
            if(p->top != -1)
            {
                opr = pop(p);

                while(priority(opr) >= priority(*(p->s)))
                {
                    *(p->t) = opr;
                    p->t++;
                    opr = pop(p);
                }
                push(p, opr);
                push(p, *(p->s));
            }
            else
                push(p, *(p->s));
            p->s++;
        }
        if(*(p->s)==')')
        {
            opr = pop(p);

            while((opr) != '(')
            {
                *(p->t) = opr;
                p->t++;
                opr = pop(p);
            }
            p->s++;
        }
    }

    while(p->top != -1)
    {
        char opr = pop(p);
        *(p->t) = opr;
        p->t++;
    }
    *(p->t) = '\0';
}

/* Returns the priority of an operator */
int priority(char c)
{
    if(c=='$')
        return 3;
    if(c=='*' || c=='/' || c=='%')
        return 2;
    else
    {
        if(c=='+' || c=='-')
            return 1;
        else
            return 0;
    }    
}

/* Displays the postfix form of given expr. */
void show(struct infix p)
{
    printf("%s\n", p.target);
}
