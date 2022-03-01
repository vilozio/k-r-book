#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand of operator */
#define NUMBER '0' /* sign of a number */

int getop(char []);
void push(double);
double pop(void);

/* calculator with Reverse Polish notation */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/' :
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: division by zero\n");
            break;
        case '\n' :
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown operation %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* max length of stack */

int sp = 0; /* next free position in stack */
double val[MAXVAL]; /* stack */

/* push: put value f in stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, not enough space for %g\n", f);
}

/* pop: take a value from top of the stack and return it */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

/* getop: get next operator or operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* accumulate integer part of number */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* accumulate fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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
