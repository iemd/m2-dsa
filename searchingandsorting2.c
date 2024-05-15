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
    /* Linear Search (Sorted Array) */

    int arr[10] = {1, 2, 3, 9, 11, 13, 17, 25, 57, 90};
    int i, num;

    system("clear");

    printf("Enter number to search:");
    scanf("%d", &num);

    for(i=0; i<=9; i++)
    {
        if(arr[9] < num || arr[i] >= num)
        {
            if(arr[i] == num)
                printf("The number is at position %d in the array.\n", i);
            else
                printf("Number is not present in the array.\n");
            break;
        }
    }
    
    return 0;
}
