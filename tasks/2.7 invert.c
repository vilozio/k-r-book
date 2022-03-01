#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    int x, b;
    x = 113;              // 1110001
    b = invert(x, 4, 3);  // 1101101
    printf("%d\n", b);
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}
