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

#define MAX1 5
#define MAX2 7

int* create(int);
void sort(int *, int);
void display(int *, int);
int* merge(int *, int *);

int main()
{
    /* Merging Of Two Arrays */

    int *a, *b, *c;

    system("clear");

    printf("Enter elements for first array:\n\n");
    a = create(MAX1);

    printf("Enter elements for second array:\n\n");
    b = create(MAX2);

    sort(a, MAX1);
    sort(b, MAX2);

    printf("First array:\n");
    display(a, MAX1);

    printf("Second array:\n");
    display(b, MAX2);

    printf("After merging:\n");
    c = merge(a, b);
    display(c, MAX1+MAX2);

    return 0;
}

/* Creates array of given size, dynamically */
int* create(int size)
{
    int *arr, i;

    arr = (int *)malloc(sizeof(int)*(size));

    for(i=0; i<size; i++)
    {
        printf("Enter the element no. %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    return arr;
}

/* Sorts array in ascending order */
void sort(int *arr, int size)
{
    int i, temp, j;

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Displays the contents of array */
void display(int *arr, int size)
{
    int i;

    for(i=0; i<size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

/* Merges two arrays of different size */
int* merge(int *a, int *b)
{
    int *arr;
    int i, j, k;
    int size = MAX1+MAX2;

    arr = (int *)malloc(sizeof(int)*(size));

    for(k=0,j=0,i=0; i<=size; i++)
    {
        if(a[k]<b[j])
        {
            arr[i] = a[k];
            k++;

            if(k>=MAX1)
            {
                for(i++; j<MAX2; j++,i++)
                    arr[i] = b[j];                
            }
        }
        else
        {
            arr[i] = b[j];
            j++;

            if(j>=MAX2)
            {
                for(i++; k<MAX1; k++,i++)
                    arr[i] = a[k];
            }
        }
    }

    return arr;
}
