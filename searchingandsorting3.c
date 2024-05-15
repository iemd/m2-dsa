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
    /* Binary Search */

    int arr[10] = {1, 2, 3, 9, 11, 13, 17, 25, 57, 90};
    int mid, lower = 0, upper = 9, num, flag = 1;

    system("clear");

    printf("Enter number to search:");
    scanf("%d", &num);

    for(mid=(lower+upper)/2; lower<=upper; mid=(lower+upper)/2)
    {
        if(arr[mid] == num)
        {
            printf("The number is at position %d in the array.\n", mid);
            flag = 0;
            break;
        }
        if(arr[mid] > num)
            upper = mid - 1;
        else
            lower = mid + 1;
    }

    if(flag)
        printf("Element is not present in the array.\n");
    
    return 0;
}
