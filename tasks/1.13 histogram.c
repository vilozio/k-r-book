#include <stdio.h>

#define IN 1 /* inside word */
#define OUT 0 /* outside word */

int main()
{
    int c, i, j, state, nlenght;
    int nwords[10];
    for (i = 0; i < 10; ++i)
        nwords[i] = 0;
    nlenght = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nlenght < 10)
                ++nwords[nlenght];
            nlenght = 0;
        } else if (state == OUT) {
            state = IN;
            ++nlenght;
        } else {
            ++nlenght;
        }
    }
    for (i = 0; i < 10; ++i) {
        printf("\n%d ", i);
        for (j = 0; j < nwords[i]; ++j)
            printf("=");
    }
    return 0;
}
