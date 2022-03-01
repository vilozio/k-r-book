#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
    int x, b;
    x = 113;                // 1110001
    b = getbits(x, 4, 3);   //   100
    printf("%d\n", b);
    return 0;
}

/* getbits: get n bits starting from postion p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
