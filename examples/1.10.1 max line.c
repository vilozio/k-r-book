#include <stdio.h>

#define MAXLINE 1000 /* maximum size of the input line */

int max; /* length of the longest line from processed lines */
char line[MAXLINE]; /* current line */
char longest[MAXLINE]; /* the longest line */

int get_input_line(void);
void copy(void);

/* print the longest line; special version */
int main()
{
    int len; /* length of the current line */
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = get_input_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0) /* was there at least one line? */
        printf("\n%s\n", longest);
    return 0;
}

/* get_input_line: special version */
int get_input_line(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: special version */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
