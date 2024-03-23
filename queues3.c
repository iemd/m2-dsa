/*
 * Data Structures: Linear Data Structures (Queues)
 * Queue is a linear data structure that permits "insertion of new element" "at one end" and
   "deletion of an element" "at the other end".
 * The end at which the "deletion" of an element "take place" is called "front", and the end
   at which "insertion" of a new element "can take place" is called "rear".
 * Applications of queue as a data structure are even more common than applications of stacks.
 * While performing tasks on a computer, it is "often necessary to wait one’s turn"
   before having access to some device or process.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void addq(int *, int, int *, int *);
int delq(int *, int *, int *);
void display(int *);

int main()
{
    /* Circular Queues */

    int arr[MAX];
    int i, front, rear;
    
    system("clear");

    /* initialise data member */
    front = rear = -1;
    for(i=0; i<MAX; i++)
        arr[i] = 0;
    
    addq(arr, 14, &front, &rear);
    addq(arr, 22, &front, &rear);
    addq(arr, 13, &front, &rear);
    addq(arr, -6, &front, &rear);
    addq(arr, 25, &front, &rear);

    printf("Elements in the circular queue:\n");
    display(arr);
    
    i = delq(arr, &front, &rear);
    if(i != -1)
        printf("Item deleted:%d\n", i);
    
    i = delq(arr, &front, &rear);
    if(i != -1)
        printf("Item deleted:%d\n", i);
    
    printf("Elements in the circular queue after deletion:\n");
    display(arr);
    
    addq(arr, 21, &front, &rear);
    addq(arr, 17, &front, &rear);
    addq(arr, 18, &front, &rear);
    addq(arr, 9, &front, &rear);
    addq(arr, 20, &front, &rear);

    printf("Elements in the circular queue after addition:\n");
    display(arr);

    addq(arr, 32, &front, &rear);

    printf("Elements in the circular queue after addition:\n");
    display(arr);

    return 0;
}

/* Adds an element to the queue */
void addq(int *arr, int item, int *pfront, int *prear)
{
    if((*prear == MAX-1 && *pfront == 0) || (*prear+1 == *pfront))
    {
        printf("Queue is full.\n");
        return;
    }

    if(*prear == MAX-1)
        *prear = 0;
    else
        (*prear)++;
    
    arr[*prear] = item;

    if(*pfront == -1)
        *pfront = 0;
}

/* Removes an element from the queue */
int delq(int *arr, int *pfront, int *prear)
{
    int data;

    if(*pfront == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    data = arr[*pfront];
    arr[*pfront] = 0;

    if(*pfront == *prear)
    {
        *pfront = -1;
        *prear = -1;
    }        
    else
    {
        if(*pfront == MAX-1)
            *pfront = 0;
        else
            (*pfront)++;
    }

    return data;
}

/* Displays element in a queue */
void display(int *arr)
{
    int i;

    for(i=0; i<MAX; i++)
        printf("%d\t", arr[i]);
    
    printf("\n");    
}
