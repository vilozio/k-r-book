#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int n = -72;
    char s[100];
    itob(n, s, 7);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b)
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
        s[i++] = num % b <= 9 ? num % b + '0' : num % b - 10 + 'A';
    } while ((num /= b) > 0);
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
