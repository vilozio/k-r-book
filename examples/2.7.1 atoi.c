#include <stdio.h>

#define STR_NUM "12345"

int atoi(char s[]);

int main()
{
    int n = atoi(STR_NUM);
    n = n + 10;
    printf("%d", n);
    return 0;
}

/* atoi: convert number from string to int */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
