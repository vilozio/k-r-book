#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_line(char *s, int lim);
void itoa(int n, char *s);
int atoi(char *s);
void reverse(char *s);
int strindex(char *s, char *t);


int main()
{
    // char s[1000];
    // int n = get_line(s, 10);
    // printf("%d\n", n);

    // char s[] = "First line s.";
    // char t[] = "line";
    // int n = strindex(s, t);
    // printf("%d\n", n);

    // int n = -2147483648;
    // char s[100];
    // itoa(n, s);
    // printf("%s\n", s);

    int n = atoi("   -12345");
    printf("%d", n);
    return 0;
}

/* getline: read line s, return length */
int get_line(char *s, int lim)
{
    int c;
    char *p = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

void itoa(int n, char *s)
{
    char *p = s;
    int sign;
    unsigned int num;
    sign = n;
    if (n << 1 == 0) { /* min negative signed integer */
        num = (unsigned int) n;
    } else if (sign < 0) {
        num = -n;
    } else {
        num = n;
    }
    do {
        *s++ = num % 10 + '0';
    } while ((num /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(p);
}

int atoi(char *s)
{
    int n, sign;
    /* ignore delimeter symbols */
    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') /* skip the sign */
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

void reverse(char *s)
{
    char c, *j;
    for (j = s + strlen(s) - 1; s < j; s++, j--) {
        c = *s;
        *s = *j;
        *j = c;
    }
}

/* strindex: find the index of t in s or return -1 if not found */
int strindex(char *s, char *t)
{
    char *i, *j, *k;
    for (i = s; *s != '\0'; s++) {
        for (j = s, k = t; *k != '\0' && *j == *k; j++, k++)
            ;
        if (k - t > 0 && *k == '\0')
            return s - i;
    }
    return -1;
}

int getch(void);
void ungetch(int);

/* getop: get next operator or operand */
int getop(char *s)
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    if (isdigit(c)) /* accumulate integer part of number */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.') /* accumulate fractional part */
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return '0';
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
