#include <stdio.h>

int main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == ' ' || c == '\t')
            ++nl;
    printf ("\n%d\n", nl);
    return 0;
}
