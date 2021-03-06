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

/* itoa: convert number n to string s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* save the sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* next digit */
    } while ((n /= 10) > 0); /* exclude it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s (result is saved in s) */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
