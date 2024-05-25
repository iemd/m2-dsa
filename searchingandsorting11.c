/* Data Structures: Algorithms (Searching And Sorting)
 * Searching is an operation "which finds the location of a given element in a list".
 * Here, we will discuss two standard searching methods—Linear search and Binary search.
 * Sorting means "arranging a set of data in some order".
 * There are different methods that are used to sort the data in ascending or descending order.
 * These methods can be divided into two categories—Internal sorting and External sorting.
*/
#include<stdio.h>
#include<stdlib.h>

void shownums(char *);
void split(char *);
void sort(char *);

void writerec(char *);

int fcloseall(void);

int main()
{
    /* External Sort */

    char str[67];    /* original file name */

    system("clear");

    printf("Enter file name:");
    scanf("%s", str);    /* record.dat */

    writerec(str);

    printf("Numbers before sorting:\n");
    shownums(str);

    split(str);
    sort(str);

    printf("\n");
    printf("Numbers after sorting:\n");
    shownums(str);

    printf("\n\n");

    return 0;
}

/* Displays the contents of file */
void shownums(char *p)
{
    FILE *fp;
    int i, count = 0;

    fp = fopen(p, "rb");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        exit(0);
    }

    while(fread(&i, sizeof(int), 1, fp) != 0)
    {
        if(count == 10)
        {
            printf("\n");
            count = 0;
        }
        printf("%d\t", i);

        count++;
    }

    fclose(fp);
}

/* Splits the original file into two files */
void split(char *p)
{
    FILE *fs, *ft;
    long int l, count;
    int i;

    fs = fopen(p, "rb");
    if(fs == NULL)
    {
        printf("Unable to open file.\n");
        exit(0);
    }

    ft = fopen("temp1.dat", "wb");    /* first partitioned file */
    if(ft == NULL)
    {
        fclose(fs);
        printf("Unable to open file.\n");
        exit(1);
    }

    fseek(fs, 0L, SEEK_END);
    l = ftell(fs);
    fseek(fs, 0L, SEEK_SET);

    l = l / (sizeof(int) * 2);

    for(count=1; count<=l; count++)
    {
        fread(&i, sizeof(int), 1, fs);
        fwrite(&i, sizeof(int), 1, ft);
    }

    fclose(ft);

    ft = fopen("temp2.dat", "wb");    /* second partitioned file */
    if(ft == NULL)
    {
        fclose(fs);
        printf("Unable to open file.\n");
        exit(2);
    }

    while(fread(&i, sizeof(int), 1, fs) != 0)
        fwrite(&i, sizeof(int), 1, ft);
    
    fcloseall();
}

/* Sorts the file */
void sort(char *p)
{
    FILE *fp[4];
    char *fnames[] = {"temp1.dat", "temp2.dat", "final1.dat", "final2.dat"};
    int i, j = 1, i1, i2, flag1, flag2, p1, p2;
    long int l;

    while(1)
    {
        for(i=0; i<=1; i++)
        {
            fp[i] = fopen(fnames[i], "rb+");

            if(fp[i] == NULL)
            {
                fcloseall();
                printf("Unable to open file.\n");
                exit(i);
            }

            fseek(fp[i], 0L, SEEK_END);
            l = ftell(fp[i]);

            if(l == 0)
                goto out;
                
            fseek(fp[i], 0L, SEEK_SET);
        }

        for(i=2; i<=3; i++)
        {
            fp[i] = fopen(fnames[i], "wb");

            if(fp[i] == NULL)
            {
                fcloseall();
                printf("Unable to open file.\n");
                exit(i);
            }
        }

        i = 2;
        i1 = i2 = 0;
        flag1 = flag2 = 1;

        while(1)
        {
            if(flag1)
            {
                if(fread(&p1, sizeof(int), 1, fp[0]) == 0)
                {
                    /* if first file ends then the whole content of second file is written in the
                     * respective target file
                    */
                    while(fread(&p2, sizeof(int), 1, fp[1]) != 0)
                        fwrite(&p2, sizeof(int), 1, fp[i]);
                    break;
                }
            }

            if(flag2)
            {
                if(fread(&p2, sizeof(int), 1, fp[1]) == 0)
                {
                    /* if second file ends then the whole content of first file is written in the
                     * respective target file
                    */
                    fwrite(&p1, sizeof(int), 1, fp[i]);

                    while(fread(&p1, sizeof(int), 1, fp[0]) != 0)
                        fwrite(&p1, sizeof(int), 1, fp[i]);
                    break;
                }
            }

            if(p1 < p2)
            {
                flag2 = 0;
                flag1 = 1;
                fwrite(&p1, sizeof(int), 1, fp[i]);
                i1++;
            }
            else
            {
                flag1 = 0;
                flag2 = 1;
                fwrite(&p2, sizeof(int), 1, fp[i]);
                i2++;
            }

            if(i1 == j)
            {
                flag1 = flag2 = 1;
                fwrite(&p2, sizeof(int), 1, fp[i]);

                for(i2++; i2<j; i2++)
                {
                    if(fread(&p2, sizeof(int), 1, fp[1]) != 0)
                        fwrite(&p2, sizeof(int), 1, fp[i]);
                }

                i1 = i2 = 0;
                i == 2 ? (i = 3) : (i = 2);
            }

            if(i2 == j)
            {
                flag1 = flag2 = 1;
                fwrite(&p1, sizeof(int), 1, fp[i]);

                for(i1++; i1<j; i1++)
                {
                    if(fread(&p1, sizeof(int), 1, fp[0]) != 0)
                        fwrite(&p1, sizeof(int), 1, fp[i]);
                }

                i1 = i2 = 0;
                i == 2 ? (i = 3) : (i = 2);
            }
        }

        fcloseall();

        remove(fnames[0]);
        remove(fnames[1]);

        rename(fnames[2], fnames[0]);
        rename(fnames[3], fnames[1]);

        j *= 2;
    }

    out:

    fcloseall();

    remove(p);
    rename(fnames[0], p);
    remove(fnames[1]);
}

/* Creates original file */
void writerec(char *p)
{
    FILE *fp;
    int i, n = 1000;
    
    fp = fopen(p, "wb");

    for (i=0; i<80; i++)
    {
        int rand_int = (rand() % n) + 1;
        fwrite(&rand_int, sizeof(int), 1, fp);
    }
    
    fclose(fp);
}
