/*
 * Data Structures: Non-Linear Data Structures (Trees)
 * In a "linked list" "each node" has a "link" which points to "another node".
 * In a "tree" structure, however, "each node" may point to "several other nodes"
   (which may then point to several other nodes, etc.).
 * Although the nodes in a "general tree" may contain "any number of pointers" to
   the "other tree nodes", "a large number of data structures" have "at the most two pointers" to
   the "other tree nodes".
 * This type of a tree is called a "binary tree".
*/
#include<stdio.h>
#include<stdlib.h>

void restoreup(int, int *);
void restoredown(int, int *, int);

void makeheap(int *, int);

void add(int, int *, int *);
int replace(int, int *, int);

int del(int *, int *);

int main()
{
    /* Heap */

    int arr[20] = {1000, 7, 10, 25, 17, 23, 27, 16, 19, 37, 42, 4, 33, 1, 5, 11};
    int i, n = 15;

    system("clear");

    makeheap(arr, n);

    printf("Heap:\n");
    for(i=1; i<=n; i++)
        printf("%d\t", arr[i]);
    
    i = 24;
    add(i, arr, &n);

    printf("\n\n");
    printf("Element added %d.\n\n", i);
    printf("Heap after addtion of an element:\n");
    for(i=1; i<=n; i++)
        printf("%d\t", arr[i]);
    
    i = replace(2, arr, n);

    printf("\n\n");
    printf("Element replaced %d.\n\n", i);
    printf("Heap after replacement of an element:\n");
    for(i=1; i<=n; i++)
        printf("%d\t", arr[i]);
    
    i = del(arr, &n);
    
    printf("\n\n");
    printf("Element deleted %d.\n\n", i);
    printf("Heap after deletion of an element:\n");
    for(i=1; i<=n; i++)
        printf("%d\t", arr[i]);
    
    printf("\n\n");

    return 0;
}

void restoreup(int i, int *arr)
{
    int val;
    val = arr[i];

    while(arr[i/2] <= val)
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = val;
}

void restoredown(int pos, int *arr, int n)
{
    int i, val;
    val = arr[pos];

    while(pos <= n/2)
    {
        i = 2 * pos;

        if((i < n) && (arr[i] < arr[i+1]))
            i++;
        if(val >= arr[i])
            break;
        
        arr[pos] = arr[i];
        pos = i;        
    }
    arr[pos] = val;
}

void makeheap(int *arr, int n)
{
    int i;

    for(i=n/2; i>=1; i--)
        restoredown(i, arr, n);
}

void add(int val, int *arr, int *n)
{
    (*n)++;
    arr[*n] = val;

    restoreup(*n, arr);
}

int replace(int i, int *arr, int n)
{
    int r = arr[1];
    arr[1] = i;

    for(i=n/2; i>=1; i--)
        restoredown(i, arr, n);
    
    return r;
}

int del(int *arr, int *n)
{
    int val;
    val = arr[1];
    arr[1] = arr[*n];
    (*n)--;

    restoredown(1, arr, *n);

    return val;
}
