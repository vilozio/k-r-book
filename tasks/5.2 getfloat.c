#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);

void ungetch(int);

int getfloat(double *pn);

int main()
{
    double n = 1;
    getfloat(&n);
    printf("%f\n", n);
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

int getfloat(double *pn)
{
    double power, e_base;
    int c, sign, e_power, e_iter;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    if (!isdigit(c) && c != 'e' && c != 'E') {
        ungetch(c);
        *pn *= sign;
        return 0;
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    if (c == 'e' || c == 'E') {
        c = getch();
        e_base = (c == '-') ? 10.0 : 0.1;
        if (c == '+' || c == '-') {
            c = getch();
            if (!isdigit(c)) {
                ungetch(c);
            }
        }
        for (e_power = 0; isdigit(c); c = getch())
            e_power = 10 * e_power + (c - '0');
        for (e_iter = 0; e_iter < e_power; e_iter++)
            power *= e_base;
    }
    *pn = sign * *pn / power;
    if (c != EOF)
        ungetch(c);
    return c;
}
