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

void addqatbeg(int *, int, int *, int *);
void addqatend(int *, int, int *, int *);

int delqatbeg(int *, int *, int *);
int delqatend(int *, int *, int *);

void display(int *);
int count(int *);

int main()
{
    /* Deque (double-ended queue) */

    int arr[MAX];
    int front, rear, i, n;

    system("clear");

    /* initialises data members */
    front = rear = -1;
    for(i=0; i<MAX; i++)
        arr[i]= 0;

    addqatend(arr, 17, &front, &rear);
    addqatbeg(arr, 10, &front, &rear);
    addqatend(arr, 8, &front, &rear);
    addqatbeg(arr, -9, &front, &rear);
    addqatend(arr, 13, &front, &rear);
    addqatbeg(arr, 28, &front, &rear);
    addqatend(arr, 14, &front, &rear);
    addqatbeg(arr, 5, &front, &rear);
    addqatend(arr, 25, &front, &rear);
    addqatbeg(arr, 6, &front, &rear);
    addqatend(arr, 21, &front, &rear);
    addqatbeg(arr, 11, &front, &rear);

    printf("Elements in a deque:\n");
    display(arr);

    n = count(arr);
    printf("Total number of elements in deque:%d\n\n", n);

    i = delqatbeg(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);
    
    i = delqatbeg(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);
    
    i = delqatbeg(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);
    
    i = delqatbeg(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);
    
    printf("Elements in a deque after deletion:\n");
    display(arr);

    addqatend(arr, 16, &front, &rear);
    addqatend(arr, 7, &front, &rear);

    printf("Elements in a deque after addition:\n");
    display(arr);

    i = delqatend(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);
    
    i = delqatend(arr, &front, &rear);
    if(i != -1)
        printf("Item extracted:%d\n", i);

    printf("Elements in a deque after deletion:\n");
    display(arr);

    n = count(arr);
    printf("Total number of elements in deque:%d\n\n", n);

    return 0;    
}

/* Adds an element at the beginning of a deque */
void addqatbeg(int *arr, int item, int *pfront, int *prear)
{
    int i, k, c;

    if(*pfront == 0 && *prear == MAX-1)
    {
        printf("Deque is full.\n");

        return;
    }

    if(*pfront == -1)
    {
        *pfront = *prear = 0;
        arr[*pfront] = item;

        return;
    }

    if(*prear != MAX-1)
    {
        c = count(arr);
        k = *prear + 1;

        for(i=1; i<=c; i++)
        {
            arr[k] = arr[k-1];
            k--;
        }

        arr[k] = item;
        *pfront = k;
        (*prear)++;
    }
    else
    {
        (*pfront)--;
        arr[*pfront] = item;
    }
}

/* Adds an element at the end of a deque */
void addqatend(int *arr, int item, int *pfront, int *prear)
{
    int i, k;

    if(*pfront == 0 && *prear == MAX-1)
    {
        printf("Deque is full.\n");

        return;
    }

    if(*pfront == -1)
    {
        *prear = *pfront = 0;
        arr[*prear] = item;

        return;
    }

    if(*prear == MAX-1)
    {
        k = *pfront - 1;

        for(i=*pfront-1; i<*prear; i++)
        {
            k = i;

            if(k == MAX-1)
                arr[k] = 0;
            else
                arr[k] = arr[i+1];
        }
        (*prear)--;
        (*pfront)--;
    }
    
    (*prear)++;
    arr[*prear] = item;
}

/* Removes an element from the *pfront end of deque */
int delqatbeg(int *arr, int *pfront, int *prear)
{
    int item;

    if(*pfront == -1)
    {
        printf("Deque is empty.\n");

        return -1;
    }

    item = arr[*pfront];
    arr[*pfront] = 0;

    if(*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;
    
    return item;
}

/* Removes an element from the *prear end of the deque */
int delqatend(int *arr, int *pfront, int *prear)
{
    int item;

    if(*pfront == -1)
    {
        printf("Deque is empty.\n");

        return -1;
    }

    item = arr[*prear];
    arr[*prear] = 0;
    (*prear)--;

    if(*prear == -1)
        *pfront = -1;
    
    return item;
}

/* Displays elements of a deque */
void display(int *arr)
{
    int i;

    //printf("\n");

    printf("front-> ");
    for(i=0; i<MAX; i++)
        printf("%d ", arr[i]);
    printf("<-rear");

    printf("\n\n");
}

/* Counts the total number of elements in deque */
int count(int *arr)
{
    int c = 0, i;

    for(i=0; i<MAX; i++)
    {
        if(arr[i] != 0)
            c++;
    }

    return c;
}
