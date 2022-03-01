#include <stdio.h>

int main()
{
    int i, lim, c;
    lim = 1000;
    char line[lim];
    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c != EOF) {
            if (c != '\n') {
                line[i] = c;
            } else {
                break;
            }
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return 0;
}
