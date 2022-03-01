#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main()
{
    char s[] = "A string with whitespaces       ";
    trim(s);
    printf("%s\n", s);
    return 0;
}

/* trim: removes from the end spaces, tabs and new lines */
int trim(char s[])
{
    int n;
    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n;
}
