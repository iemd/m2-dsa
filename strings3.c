/*
 * Data Structures: Linear Data Structures (Strings)
 * The way a "group of integers" can be stored in an "integer array", a "group of characters" can also be stored in a "character array".
 * An array of characters is often called a string.
 * A string constant is a one-dimensional array of characters terminated by a null ('\0') character.
 * In fact, a string not terminated by a '\0' is not really a string, but merely a collection of characters.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 6

char *names[MAX];
int count;

int add(char *);
void swap(int, int);
void show();

int main()
{
    /* Array of Pointers To Strings */

    int flag;

    system("clear");

    flag = add("akshay");
    if(flag == 0)
        printf("Unable to add string\n");

    flag = add("parag");
    if(flag == 0)
        printf("Unable to add string\n");

    flag = add("raman");
    if(flag == 0)
        printf("Unable to add string\n");

    flag = add("srinivas");
    if(flag == 0)
        printf("Unable to add string\n");

    flag = add("gopal");
    if(flag == 0)
        printf("Unable to add string\n");

    flag = add("rajesh");
    if(flag == 0)
        printf("Unable to add string\n");

    printf("Names before swapping:\n");
    show();

    swap(2, 3);
    printf("Names after swapping:\n");
    show();
    
    return 0;
}

/* Adds given string */
int add(char *s)
{
    if(count < MAX)
    {
        names[count] = s;
        count++;
        return 1;
    }
    else
        return 0;
}

/* Swaps the names at given two positions */
void swap(int i, int j)
{
    char *temp;

    temp = names[i];
    names[i] = names[j];
    names[j] = temp;
}

/* Displays the elements */
void show()
{
    int i;

    for(i=0; i<count; i++)
        puts(names[i]);
    printf("\n");
}
