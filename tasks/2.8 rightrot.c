#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    int x, b;
    x = 113;              // 1110001
    b = rightrot(x, 3);   //   11110
    printf("%d\n", b);
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int p;
    // search for the position of last-plus-one 1-bit in the x number
    // same thing as finding log base 2
    for (p = 1; p <= 32; p++) {
        if (x >> p == 0) {
            return ((x & ~(~0 << n)) << (p - n)) | (x >> n);
        }
    }
    return x;
}
