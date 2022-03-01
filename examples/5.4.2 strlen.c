#include <stdio.h>

/* strlen: returns the length of the string */
int my_strlen(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}