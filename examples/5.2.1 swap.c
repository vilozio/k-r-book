#include <stdio.h>

void swap(int *px, int *py) /* swap of *px and *py */
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
