#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d\n", bitcount(101));
    return 0;
}

/* bitcount: count one bits in number x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
