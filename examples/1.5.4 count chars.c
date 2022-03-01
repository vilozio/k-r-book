#include <stdio.h>
/* count input characters; 2st version */
int main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("\n%.0f\n", nc);
    return 0;
}
