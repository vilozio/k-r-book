#include <stdio.h>

#define MAXLINE 1000 /* maximum size of the input line */

int get_input_line(char line[], int lim);
void copy(char to[], char from[]);

/* print the longest line */
int main()
{
    int len; /* length of the current line */
    int max; /* length of the longest line from processed lines */
    char line[MAXLINE]; /* current line */
    char longest[MAXLINE]; /* the longest line */
    max = 0;
    while ((len = get_input_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        if (len == MAXLINE - 1) {
            while ((len = get_input_line(line, MAXLINE)) > 0 && line[len - 1] != '\n')
                max += len;
            max += len; /* the end of the line that is out of range */
        }
    }
    if (max > 0)  { /* was there at least one line? */
        printf("\nLongest line: %s\n", longest);
        printf("Length of the longest line: %d\n", max - 1);
    }
    return 0;
}

/* get_input_line: reads a line into the first parameter, returns the length of it */
int get_input_line(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copies from 'from' to 'to' */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
