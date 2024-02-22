/*
 * Data Structures: Linear Data Structures (Arrays)
 * There are two ways of representing linear data structures in memory.
 * One way is "to have the linear relationship between the elements" by means of "sequential memory locations".
 * Such linear structures are called arrays.
 * The other way is "to have the linear relationship between the elements" represented by means of "pointers or links".
 * Such linear structures are called linked lists.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void insert(int *, int pos, int num);
void del(int *, int pos);
void reverse(int *);
void display(int *);
void search(int *, int num);

int main()
{
    /* Array Operations */

    int arr[5];

    system("clear");

    insert(arr, 1, 11);
    insert(arr, 2, 12);
    insert(arr, 3, 13);
    insert(arr, 4, 14);
    insert(arr, 5, 15);
    printf("Elements of Array:\n");
    display(arr);

    del(arr, 5);
    del(arr, 2);
    printf("After deletion:\n");
    display(arr);

    insert(arr, 2, 222);
    insert(arr, 5, 555);
    printf("After insertion:\n");
    display(arr);

    reverse(arr);    
    printf("After reversing:\n");
    display(arr);

    search(arr, 222);
    search(arr, 666);

    return 0;
}

/* Inserts an element num at given position pos */
void insert(int *arr, int pos, int num)
{
    /* shift elements to right */
    int i;
    for(i=MAX-1; i>=pos; i--)
        arr[i] = arr[i-1];
    arr[i] = num;
}

/* Deletes an element from the given position pos */
void del(int *arr, int pos)
{
    /* skip to the desired position */
    int i;
    for(i=pos; i<MAX; i++)
        arr[i-1] = arr[i];
    arr[i-1] = 0;
}

/* Reverses the entire array */
void reverse(int *arr)
{
    int i;
    for(i=0; i<MAX/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[MAX-1-i];
        arr[MAX-1-i] = temp;
    }
}

/* Searches array for a given element num */
void search(int *arr, int num)
{
    /* traverse the array */
    int i;
    for(i=0; i<MAX; i++)
    {
        if(arr[i] == num)
        {
            printf("The element %d is present at %dth position.\n\n", num, i+1);
            return;
        }
    }
    if(i==MAX)
    {
        printf("The element %d is not present in the array.\n\n", num);
    }
}

/* Displays the contents of an array */
void display(int *arr)
{
    /* traverse the entire array */
    int i;
    for(i=0; i<MAX; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
