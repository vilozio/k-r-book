#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "I am a teapot. I can't brew coffee.";
    char s2[] = "abc";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k, c, f;
    for (i = j = 0; s1[i] != '\0'; i++) {
        f = 0;
        c = '\0';
        for (k = 0; s2[k] != '\0' && !f; k++) {
            if (s1[i] == s2[k]) {
                c = s1[i];
                f = 1;
            }
        }
        if (s1[i] != c)
            s1[j++] = s1[i];
    }
    s1[i] = '\0';
}
