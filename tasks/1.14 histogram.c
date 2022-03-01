#include <stdio.h>

int main()
{
    int c, i, j, nlenght;
    nlenght = 60;
    int nchars[nlenght];
    for (i = 0; i < nlenght; ++i)
        nchars[i] = 0;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++nchars[c - '0'];
        else if (c >= 'A' && c <= 'Z')
            ++nchars[c - 'A' + ('9' - '0')];
        else if (c >= 'a' && c <= 'z')
            ++nchars[c - 'a' + ('Z' - 'A')];
    for (i = 0; i < nlenght; ++i) {
        printf("\n%2d ", i);
        for (j = 0; j < nchars[i]; ++j)
            printf("=");
    }
    return 0;
}
