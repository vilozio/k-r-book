#include <stdio.h>
/* count input lines */
int main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf ("\n%d\n", nl);
    return 0;
}
