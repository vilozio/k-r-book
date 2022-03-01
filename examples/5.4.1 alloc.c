#include <stdio.h>

#define ALLOCSIZE 10000          /* the size of allowed space */

static char allocbuf[ALLOCSIZE]; /* memory for alloc */
static char *allocp = allocbuf;  /* pointer on free space */

char *alloc(int n) /* returns a pointer on n chars */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n; /* space is free */
        return allocp - n; /* old space */
    } else /* no free space */
        return 0;
}
void afree(char *p) /* free the space allocated for a pointer */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
