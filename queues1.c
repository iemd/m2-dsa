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

int main()
{
    /* Queue As An Array */

    int arr[MAX];
    int front = -1, rear = -1, i;

    system("clear");

    addq(arr, 23, &front, &rear);
    addq(arr, 9, &front, &rear);
    addq(arr, 11, &front, &rear);
    addq(arr, -10, &front, &rear);
    addq(arr, 25, &front, &rear);
    addq(arr, 16, &front, &rear);
    addq(arr, 17, &front, &rear);
    addq(arr, 22, &front, &rear);
    addq(arr, 19, &front, &rear);
    addq(arr, 30, &front, &rear);
    addq(arr, 32, &front, &rear);

    i = delq(arr, &front, &rear);
    if(i != -1)
        printf("Item deleted:%d\n", i);
    
    i = delq(arr, &front, &rear);
    if(i != -1)
        printf("Item deleted:%d\n", i);
    
    i = delq(arr, &front, &rear);
    if(i != -1)
        printf("Item deleted:%d\n", i);
    
    return 0;
}

/* Adds an element to the queue */
void addq(int *arr, int item, int *pfront, int *prear)
{
    if(*prear == MAX-1)
    {
        printf("Queue is full.\n");
        return;
    }

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
        printf("Queue is Empty.\n");
        return -1;
    }

    data = arr[*pfront];
    arr[*pfront] = 0;

    if(*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;

    return data;
}
