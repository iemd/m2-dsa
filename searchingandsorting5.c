/* Data Structures: Algorithms (Searching And Sorting)
 * Searching is an operation "which finds the location of a given element in a list".
 * Here, we will discuss two standard searching methods—Linear search and Binary search.
 * Sorting means "arranging a set of data in some order".
 * There are different methods that are used to sort the data in ascending or descending order.
 * These methods can be divided into two categories—Internal sorting and External sorting.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    /* Selection Sort */

    int arr[5] = {25, 17, 31, 13, 2};
    int i, j, temp;

    system("clear");

    printf("Selection sort.\n\n");
    printf("Array before sorting:\n");
    for(i=0; i<=4; i++)
        printf("%d\t", arr[i]);
    
    for(i=0; i<=3; i++)
    {
        for(j=i+1; j<=4; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n");
    printf("Array after sorting:\n");
    for(i=0; i<=4; i++)
        printf("%d\t", arr[i]);
    
    printf("\n\n");
        
    return 0;
}
