#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);

void ungetch(int);

int getint(int *pn);

int main()
{
    int n = 1;
    getint(&n);
    printf("%d\n", n);
    return 0;
}

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


/* getint: reads next integer from input to *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ; /* pass delimiter characters */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
