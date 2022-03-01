#include <stdio.h>

int main()
{
    int x = 1, y = 2, z[10];
    int *ip; /* ip - pointer to int */
    ip = &x; /* ip points to x now */
    y = *ip; /* y equals to 1 now */
    *ip = 0; /* x equals to 0 now */
    ip = &z[0]; /* ip points to z[0] now */
    return 0;
}
