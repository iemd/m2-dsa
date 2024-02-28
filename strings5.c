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

int xstrsearch(char *, char *);
void show();

int main()
{
    /* Pattern Matching (Brute Force Algorithm) */

    char s1[] = "NagpurKicit";
    char s2[] = "Kicit";
    int pos;

    system("clear");

    printf("String s1:%s\n\n", s1);
    printf("String s2:%s\n\n", s2);

    /* search if s2 is present in s1 */
    pos = xstrsearch(s1, s2);
    printf("The pattern string is found at position:%d\n", pos);

    return 0;
}

/* Searches for the given pattern s2 into the string s1 */
int xstrsearch(char *s1, char *s2)
{
    int i, j, k;

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    for(i=0; i<=l1-l2; i++)
    {
        j = 0;
        k = i;

        while((s1[k]==s2[j]) && (j<l2))
        {
            k++;
            j++;
        }
        if(j == l2)
            return i;
    }
    return -1;
}
