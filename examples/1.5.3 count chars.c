#include <stdio.h>
/* count input characters; 1st version */
int main()
{
    long nc;
    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf("\n%ld\n", nc);
    return 0;
}
