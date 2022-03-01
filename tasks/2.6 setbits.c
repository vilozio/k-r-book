#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int x, y, b;
    x = 113;                  // 1110001
    y = 31;                   //    1111
    b = setbits(x, 4, 3, y);  // 1111101
    printf("%d\n", b);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x >> (p + 1) << (p + 1)) | (((y & ~(~0 << n)) << (p + 1 - n))) | (x & ~(~0 << (p + 1 - n)));
}
