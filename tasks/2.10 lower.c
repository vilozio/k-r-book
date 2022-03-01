#include <stdio.h>

int lower(int c);

int main()
{
    putchar(lower('T'));
    putchar(lower('E'));
    putchar(lower('S'));
    putchar(lower('T'));
    printf("\n");
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
