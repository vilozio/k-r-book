#include <stdio.h>
// #include <math.h>

int main()
{
    printf("%d\n", -1L < 1U);   // signed long and unsigned int
    printf("%d\n", -1L > 1UL);  // signed long and unsigned long
    printf("%lu\n", (signed long) -1L);  // the actual value of casting -1 unsigned long to signed
    return 0;
}
