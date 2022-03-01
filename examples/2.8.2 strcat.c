#include <stdio.h>

void strcat2(char s[], char t[]);

int main()
{
    char s[1000] = "I am a teapot.";
    char t[] = " I can't brew coffee.";
    strcat2(s, t);
    printf("%s\n", s);
    return 0;
}

/* strcat: put t into the end of s; s has enough size */
void strcat2(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find the end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}
