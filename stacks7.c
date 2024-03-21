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
#include<math.h>
#include<ctype.h>

#define MAX 50

struct postfix
{
    int stack[MAX];
    int top, nn;
    char *s;
};

void initpostfix(struct postfix *);
void setexpr(struct postfix *, char *);

void push(struct postfix *, int);
int pop(struct postfix *);

void calculate(struct postfix *);
void show(struct postfix);

int main()
{
    /* Applications Of Stacks (Evaluation Of Postfix Expression) */

    struct postfix q;
    char expr[MAX];

    system("clear");

    initpostfix(&q);

    printf("Enter postfix expression to be evaluated:\n");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    setexpr(&q, expr);
    calculate(&q);
    show(q);

    return 0;
}

/* Initializes structure elements */
void initpostfix(struct postfix *p)
{
    p->top = -1;
}

/* Sets s to point to the given expr. */
void setexpr(struct postfix *p, char *str)
{
    p->s = str;
}

/* Adds digit to the stack */
void push(struct postfix *p, int item)
{
    if(p->top == MAX-1)
        printf("Stack is full.\n");
    else
    {
        p->top++;
        p->stack[p->top] = item;
    }
}

/* Pops digit from the stack */
int pop(struct postfix *p)
{
    int data;
    
    if(p->top == -1)
    {
        printf("Stack is empty.\n");
        //return NULL;
    }

    data = p->stack[p->top];
    p->top--;

    return data;
}

/* Evaluates the postfix expression */
void calculate(struct postfix *p)
{
    int n1, n2, n3;

    while(*(p->s))
    {
        /* skip whitespace, if any */
        if(*(p->s)==' ' || *(p->s)=='\t')
        {
            p->s++;
            continue;
        }
        /* if digit is encountered */
        if(isdigit(*(p->s)))
        {
            p->nn = *(p->s)-'0';
            push(p, p->nn);
        }
        else
        {
            /* if operator is encountered */
            n1 = pop(p);
            n2 = pop(p);

            switch(*(p->s))
            {
                case '+':
                    n3 = n2 + n1;
                    break;

                case '-':
                    n3 = n2 - n1;
                    break;

                case '/':
                    n3 = n2 / n1;
                    break;

                case '*':
                    n3 = n2 * n1;
                    break;

                case '%':
                    n3 = n2 % n1;
                    break;

                case '$':
                    n3 = (int)pow(n2, n1);
                    break;

                default:
                    printf("Unknown operator\n");
                    exit(1);
            }

            push(p, n3);
        }
        p->s++;
    }
}

/* Displays the result */
void show(struct postfix p)
{
    p.nn = pop(&p);
    printf("Result is:%d\n", p.nn);
}
