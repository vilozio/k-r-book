#include <stdio.h>
#include <ctype.h>

#define STR_NUM "   -12345"

int atoi(char s[]);

int main()
{
    int n = atoi(STR_NUM);
    n = n + 10;
    printf("%d", n);
    return 0;
}

/* atoi: convert number from string to int; version 2 */
int atoi(char s[])
{
    int i, n, sign;
    /* ignore delimeter symbols */
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip the sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
