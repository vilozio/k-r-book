#include <stdio.h>

int main()
{
    int c;
    int flag = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if (flag == 0) {
                flag = 1;
                putchar(c);
            }
        } else {
            flag = 0;
            putchar(c);
        }
    }
    return 0;
}
