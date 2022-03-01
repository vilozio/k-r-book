#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    int i;
    char s1[] = "I am a teapot. I can't brew coffee.";
    char s2[] = "abc";
    i = any(s1, s2);
    printf("%d\n", i);
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, k, f;
    f = 0;
    k = -1;
    for (i = 0; s1[i] != '\0' && !f; i++) {
        for (j = 0; s2[j] != '\0' && !f; j++) {
            if (s1[i] == s2[j]) {
                k = i;
                f = 1;
            }
        }
    }
    return k;
}
