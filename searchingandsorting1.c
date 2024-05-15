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
    /* Linear Search (Unsorted Array) */

    int arr[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
    int i, num;

    system("clear");

    printf("Enter number to search:");
    scanf("%d", &num);

    for(i=0; i<=9; i++)
    {
        if(arr[i] == num)
            break;
    }

    if(i == 10)
        printf("Number is not present in the array.\n");
    else
        printf("The number is at position %d in the array.\n", i);
    
    return 0;
}
