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

int xstrlen(char *);
void xstrcpy(char *, char *);
void xstrcat(char *, char *);
int xstrcmp(char *, char *);
void show(char *);

int main()
{
    /* Operations On Strings */

    char s1[] = "kicit";
    char s2[] = "Nagpur";
    char s3[20];
    int len;

    system("clear");

    printf("String s1:%s\n", s1);

    len = xstrlen(s1);
    printf("length of the string s1:%d\n", len);

    printf("String s2:%s\n", s2);

    xstrcpy(s3, s1);
    printf("String s3 after copying s1 to it:%s\n", s3);

    xstrcat(s3, s2);
    printf("String s3 after concatenation:%s\n", s3);

    if(xstrcmp(s1, s2) == 0)
        printf("The strings s1 and s2 are similar\n");
    else
        printf("The strings s1 and s2 are not similar\n");

    return 0;
}

/* Finds the length of the string */
int xstrlen(char *s)
{
    int l = 0;

    while(*s)
    {
        l++;
        s++;
    }

    return l;
}

/* Copies source string s to the target string t */
void xstrcpy(char *t, char *s)
{
    while(*s)
    {
        *t = *s;
        t++;
        s++;
    }
    *t = '\0';
}

/* Concatenates the two strings */
void xstrcat(char *t, char *s)
{
    while(*t)
        t++;
    while(*s)
        *t++ = *s++;
    *t = '\0';
}

/* Compares two strings s and t for equality */
int xstrcmp(char *s, char *t)
{
    while(*s == *t)
    {
        if(!(*s))
            return 0;
        s++;
        t++;
    }

    return (*s - *t);
}
