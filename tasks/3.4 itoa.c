#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n = -2147483648;
    char s[100];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

// itoa function in the example code cannot deal with INT_MIN because
// in two's complement representation last bit is used as a sign;
// e.g. we have 8 bit word with allowed values from 0 to 255,
// number 200 is 1100 1000 in 2 based system.
// With two's complement the last bit indicates if the number
// is negative, so now allowed values are from -128 to 127
// and 1100 1000 is now -72. Easy to show that the minimum
// negative value here -128 (1000 000) at the same time
// should represent negative zero (-0).
void itoa(int n, char s[])
{
    int i, sign;
    unsigned int num;
    sign = n;
    if (n << 1 == 0) { /* min negative signed integer */
        num = (unsigned int) n;
    } else if (sign < 0) {
        num = -n;
    } else {
        num = n;
    }
    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
