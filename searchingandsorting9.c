/* Data Structures: Algorithms (Searching And Sorting)
 * Searching is an operation "which finds the location of a given element in a list".
 * Here, we will discuss two standard searching methods—Linear search and Binary search.
 * Sorting means "arranging a set of data in some order".
 * There are different methods that are used to sort the data in ascending or descending order.
 * These methods can be divided into two categories—Internal sorting and External sorting.
*/
#include<stdio.h>
#include<stdlib.h>

void makeheap(int[], int);
void heapsort(int[], int);

int main()
{
    /* Heap Sort */

    int arr[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
    int i;

    system("clear");

    printf("Heap Sort\n\n");

    makeheap(arr, 10);

    printf("Before Sorting:\n");
    for(i=0; i<=9; i++)
        printf("%d\t", arr[i]);
    
    heapsort(arr, 10);

    printf("\n\n");
    printf("After Sorting:\n");
    for(i=0; i<=9; i++)
        printf("%d\t", arr[i]);
    
    printf("\n\n");

    return 0;
}

/* Creates heap from the tree */
void makeheap(int x[], int n)
{
    int i, val, s, f;

    for(i=1; i<n; i++)
    {
        val = x[i];
        s = i;
        f = (s - 1)/2;

        while(s > 0 && x[f] < val)
        {
            x[s] = x[f];
            s = f;
            f = (s - 1)/2;
        }

        x[s] = val;
    }
}

/* Sorts heap */
void heapsort(int x[], int n)
{
    int i, s, f, ivalue;

    for(i=n-1; i>0; i--)
    {
        ivalue = x[i];
        x[i] = x[0];
        f = 0;

        if(i == 1)
            s = -1;
        else
            s = 1;
        
        if(i > 2 && x[2] > x[1])
            s = 2;
        
        while(s >= 0 && ivalue < x[s])
        {
            x[f] = x[s];
            f = s;
            s = 2 * f + 1;

            if(s+1 <= i-1 && x[s] < x[s+1])
                s++;
            
            if(s > i-1)
                s = -1;                
        }

        x[f] = ivalue;
    }
}
