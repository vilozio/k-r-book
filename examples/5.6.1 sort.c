#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max number of strings */
char *lineptr[MAXLINES]; /* ponters on strings */

int readlines(char *lineptr[], int nlines);
void wntelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sorting of strings */
main()
{
    int nlines; /* number of read lines */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: too many lines\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of a string */

int getline(char *, int);
char *alloc(int);

/* readlines: read lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* remove character \n */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write lines */
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j);

/* qsort: sorts v[left]...v[right] in ascending order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right) /* do nothing if */
        return;        /* the array has less than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: swap two elements v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
