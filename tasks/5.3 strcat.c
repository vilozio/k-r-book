#include <stdio.h>

void strcat2(char *s, char *t);

int main()
{
    char s[1000] = "I am a teapot.";
    char t[] = " I can't brew coffee.";
    strcat2(s, t);
    printf("%s\n", s);
    return 0;
}

void strcat2(char *s, char *t)
{
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}
