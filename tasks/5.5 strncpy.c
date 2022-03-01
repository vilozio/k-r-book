#include <stdio.h>

void strncpy2(char *s, char *t, int n);
void strncat2(char *s, char *t, int n);
int strncmp2(char *s, char *t, int n);

int main()
{
    char s[1000] = "I am a teapot.";
    char t[] = " I can't brew coffee.";
    strncat2(s, t, 5);
    printf("%s\n", s);
    strncpy2(s, t, 5);
    printf("%s\n", s);
    int compared = strncmp2(s, t, 4);
    printf("%d\n", compared);
    return 0;
}

void strncpy2(char *s, char *t, int n)
{
    while ((n-- > 0) && (*s++ = *t++))
        ;
}

void strncat2(char *s, char *t, int n)
{
    while (*s)
        s++;
    while ((n-- > 0) && (*s++ = *t++))
        ;
}

int strncmp2(char *s, char *t, int n)
{
    for (; (n > 0) && (*s == *t); n--, s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
