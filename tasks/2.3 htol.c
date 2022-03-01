#include <stdio.h>

int htol(char s[]);

int main()
{
    printf("%d\n", htol("0xAFbf123"));
    printf("%d\n", 0xAFbf123);
    return 0;
}

int htol(char s[])
{
    int i, n;
    n = 0;
    for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        }
        if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
        }
        if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        }
    }
    return n;
}
