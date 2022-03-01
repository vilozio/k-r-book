#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int n = -777;
    char s[100];
    itoa(n, s, 3);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;
    unsigned int num;
    sign = n;
    if (n << 1 == 0) {
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
    for (; w - i > 0; i++) {
        s[i] = ' ';
    }
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
