#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char s[1000] = "I am a teapot. I can't brew coffee.";
    char t[] = " I can't brew coffee.";
    int is_end = strend(s, t);
    printf("%d\n", is_end);
    return 0;
}

int strend(char *s, char *t)
{
    char *p1 = t;
    char *p2 = s;
    while (*s)
        s++;
    while (*t)
        t++;
    while (*s == *t) {
        if (t - p1 == 0)
            return 1;
        if (s - p2 == 0)
            return 0;
        s--, t--;
    }
    return 0;
}
