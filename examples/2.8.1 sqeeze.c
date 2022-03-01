#include <stdio.h>

void squeeze(char s[], int c);

int main()
{
    char s[] = "I am a teapot";
    squeeze(s, 'a');
    printf("%s\n", s);
    return 0;
}

/* squeeze: remove all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[i] = '\0';
}
