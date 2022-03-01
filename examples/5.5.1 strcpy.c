#include <stdio.h>

/* strcpy: copy t in s; a version with indexed array */
void strcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy: copy t in s: version 1 (with pointers) */
void strcpy(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copy t in s: version 2 (with pointers) */
void strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* strcpy: copy t in s: version 3 (with pointers) */
void strcpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}
