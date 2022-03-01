#include <stdio.h>

#define MAXLINE 1000 /* maximum size of the input line */

void reverse(char line[], int len);
int get_input_line(char line[], int lim);
void copy(char to[], char from[], int to_shift, int lim);

/* print the longest line */
int main()
{
    int len; /* length of the current line */
    char line[MAXLINE]; /* current line */
    char longest[MAXLINE]; /* the longest line */
    int to_shift = 0;
    while ((len = get_input_line(line, MAXLINE)) > 0) {
        if (line[len] == '\n') {
            reverse(line, len - 1);
        } else {
            reverse(line, len);
        }
        copy(longest, line, to_shift, MAXLINE);
        if (to_shift + len < MAXLINE - 1) {
            to_shift += len + 1;
        } else {
            to_shift = MAXLINE - 1;
        }
    }
    if (to_shift > 0)  { /* was there at least one line? */
        longest[to_shift] = '\0';
        printf("\n%s", longest);
    }
    return 0;
}

void reverse(char line[], int len) {
    int i;
    char tmp;
    for (i = 0; i < (len + 1) / 2; ++i) {
        tmp = line[i];
        line[i] = line[len - i];
        line[len - i] = tmp;
    }
}

/* get_input_line: reads a line into the first parameter, returns the length of it */
int get_input_line(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
    }
    return i;
}

/* copy: copies from 'from' to 'to' */
void copy(char to[], char from[], int to_shift, int lim)
{
    int i;
    i = 0;
    while ((to_shift + i < lim - 1) && ((to[to_shift + i] = from[i]) != '\0'))
        ++i;
}
