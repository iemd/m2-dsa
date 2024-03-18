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
    int top, l;
};

void initinfix(struct infix *);
void setexpr(struct infix *, char *);
void strreverse(char *);

void push(struct infix *, char);
char pop(struct infix *);

void convert(struct infix *);
int priority(char c);
void show(struct infix);

int main()
{
    /* Applications Of Stacks (Infix To Prefix Conversion) */

    struct infix q;
    char expr[MAX];

    system("clear");

    initinfix(&q);

    printf("Enter an expression in infix form:\n");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';
    
    setexpr(&q, expr);
    convert(&q);

    printf("The Prefix expression is:\n");
    show(q);

    return 0;
}

/* Initializes elements of structure variable */
void initinfix(struct infix *pq)
{
    pq->top = -1;
    strcpy(pq->target, "");
    strcpy(pq->stack, "");
    pq->l = 0;
}

/* Reverses the given expression */
void setexpr(struct infix *pq, char *str)
{
    pq->s = str;
    //strrev(pq->s);
    strreverse(pq->s);
    pq->l = strlen(pq->s);
    *(pq->target + pq->l) = '\0';
    pq->t = pq->target + (pq->l - 1);
}
void strreverse(char *str)
{
    int l = strlen(str);
    char ch, *t = (str + l - 1);
    int i = 0;

    while(i < l/2)
    {
        ch = *str;
        *str = *t;
        *t = ch;

        str++;
        t--;
        i++;
    }
}

/* Adds an operator to the stack */
void push(struct infix *pq, char c)
{
    if(pq->top == MAX-1)
        printf("Stack is full.\n");
    else
    {
        pq->top++;
        pq->stack[pq->top] = c;
    }
}

/* Pops an operator from the stack */
char pop(struct infix *pq)
{
    if(pq->top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        char item = pq->stack[pq->top];
        pq->top--;
        return item;
    }
}

/* Converts the infix expr. to prefix form */
void convert(struct infix *pq)
{
    char opr;

    while(*(pq->s))
    {
        if(*(pq->s)==' ' || *(pq->s)=='\t')
        {
            pq->s++;
            continue;
        }        
        if(isdigit(*(pq->s)) || isalpha(*(pq->s)))
        {
            while(isdigit(*(pq->s)) || isalpha(*(pq->s)))
            {
                *(pq->t) = *(pq->s);
                pq->s++;
                pq->t--;
            }
        }
        if(*(pq->s)==')')
        {
            push(pq, *(pq->s));
            pq->s++;
        }
        if(*(pq->s)=='*' || *(pq->s)=='+' || *(pq->s)=='/' || *(pq->s)=='%' || *(pq->s)=='-' || *(pq->s)=='$')
        {
            if(pq->top != -1)
            {
                opr = pop(pq);

                while(priority(opr) > priority(*(pq->s)))
                {
                    *(pq->t) = opr;
                    pq->t--;
                    opr = pop(pq);
                }
                push(pq, opr);
                push(pq, *(pq->s));
            }
            else
                push(pq, *(pq->s));
            pq->s++;
        }
        if(*(pq->s)=='(')
        {
            opr = pop(pq);

            while(opr != ')')
            {
                *(pq->t) = opr;
                pq->t--;
                opr = pop(pq);
            }
            pq->s++;
        }
    }

    while(pq->top != -1)
    {
        opr = pop(pq);
        *(pq->t) = opr;
        pq->t--;
    }
    pq->t++;
}

/* Returns the priority of the operator */
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

/* Displays the prefix form of given expr. */
void show(struct infix pq)
{
    while(*(pq.t))
    {
        printf("%c", *(pq.t));
        pq.t++;
    }
    printf("\n");
}
