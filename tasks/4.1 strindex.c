#include <stdio.h>

int strindex(char s[], char t[]);

char pattern[] = "ould";

int main()
{
    int idx;
    char s[] = "Maybe I would do the work. Maybe he could.";
    idx = strindex(s, pattern);
    printf("%d\n", idx);
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k, t_len;
    for (t_len = -1; t[t_len + 1] != '\0'; t_len++)
        ;
    for (i = -1; s[i + 1] != '\0'; i++)
        ;
    for (; i >= 0; i--) {
        for (j = i, k = t_len; k >= 0 && j >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k == -1)
            return j;
    }
    return -1;
}
