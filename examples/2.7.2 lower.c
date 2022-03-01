#include <stdio.h>
// #include <ctype.h>

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

/* lower: convert character to lower case, for ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
