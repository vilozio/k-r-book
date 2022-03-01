#include <stdio.h>

#define DELIM '-'

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "a-z0-9";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;
    for(j = i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == DELIM) {
            if (i > 0 && s1[i + 1] != '\0') {
                for (k = s1[i - 1] + 1; k < s1[i + 1]; k++, j++) {
                    s2[j] = k;
                }
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[++j] = '\0';
}
