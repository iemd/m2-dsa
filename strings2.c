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

#define MAX1 6
#define MAX2 20

char masterlist[MAX1][MAX2];
int count;

int add(char *s);
int find(char *s);

int main()
{
    /* A Two-Dimensional Array of Strings */

    char yourname[MAX2];
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

    printf("Enter your name:");
    scanf("%s", yourname);

    flag = find(yourname);
    if(flag == 1)
        printf("Welcome, you can enter the palace\n");
    else
        printf("Sorry, you are a trespasser\n");

    return 0;
}

/* Adds string to the array */
int add(char *s)
{
    if(count < MAX1)
    {
        if(strlen(s) < MAX2)
        {
            strcpy(&masterlist[count][0], s);
            count++;
            return 1;
        }
    }

    return 0;
}

/* Finds the given string */
int find(char *s)
{
    int flag = 0, i;

    for(i=0; i<count; i++)
    {
        if(strcmp(&masterlist[i][0], s) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}