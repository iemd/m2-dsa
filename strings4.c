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

int main()
{
    /* Limitation Of Array Of Pointers To Strings */

    char *name[5];
    char str[20];
    int i;

    system("clear");

    for(i=0; i<5; i++)
    {
        printf("Enter a String:");
        scanf("%s", str);
        //fgets(str, 20, stdin);

        name[i] = (char *)malloc(strlen(str)+1);
        strcpy(name[i], str);
    }

    printf("\n");

    printf("The strings are:\n");
    for(i=0; i<5; i++)
        printf("%s\n", name[i]);

    for(i=0; i<5; i++)
        free(name[i]);

    return 0;
}
