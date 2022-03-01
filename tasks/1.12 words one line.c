#include <stdio.h>

#define IN 1 /* inside word */
#define OUT 0 /* outside word */

int main()
{
    int c, state, flag;
    state = OUT;
    flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (flag == 0) {
                flag = 1;
                putchar('\n');
            }
        } else if (state == OUT) {
            state = IN;
            flag = 0;
            putchar(c);
        } else {
            putchar(c);
        }
    }
    return 0;
}
