/* Data Structures: Algorithms (Searching And Sorting)
 * Searching is an operation "which finds the location of a given element in a list".
 * Here, we will discuss two standard searching methods—Linear search and Binary search.
 * Sorting means "arranging a set of data in some order".
 * There are different methods that are used to sort the data in ascending or descending order.
 * These methods can be divided into two categories—Internal sorting and External sorting.
*/
#include<stdio.h>
#include<stdlib.h>

void quicksort(int *, int, int);
int split(int *, int, int);

int main()
{
    /* Quick Sort:
     * This algorithm is based on the fact that it is faster and easier to sort two small arrays
       than one larger one.
     * The basic strategy of quick sort is to divide and conquer.
    */

    int arr[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
    int i;

    system("clear");

    printf("Quick sort.\n\n");
    printf("Array before sorting:\n");
    for(i=0; i<=9; i++)
        printf("%d\t", arr[i]);
    
    quicksort(arr, 0, 9);

    printf("\n");
    printf("Array after sorting:\n");
    for(i=0; i<=9; i++)
        printf("%d\t", arr[i]);
    
    printf("\n\n");
        
    return 0;
}

void quicksort(int a[], int lower, int upper)
{
    int i;

    if(upper > lower)
    {
        i = split(a, lower, upper);
        quicksort(a, lower, i-1);
        quicksort(a, i+1, upper);
    }
}

int split(int a[], int lower, int upper)
{
    int i, p, q, t;

    p = lower + 1;
    q = upper;
    i = a[lower];

    while(q >= p)
    {
        while(a[p] < i)
            p++;
        
        while(a[q] > i)
            q--;
        
        if(q > p)
        {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }

    t = a[lower];
    a[lower] = a[q];
    a[q] = t;

    return q;
}
