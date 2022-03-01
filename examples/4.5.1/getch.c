#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer ungetch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* get (possibly returned) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* return back a character to input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
