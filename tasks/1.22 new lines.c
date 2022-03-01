#include <stdio.h>

#define MAXLEN 1000
#define LINE_LEN 10

int print_line(char line[], int i);
void move_to_start(char line[], int from_idx, int len);

int main()
{
    int c, i, delim_idx;
    char line[MAXLEN];
    delim_idx = 0;
    i = 0;
    while ((c = getchar()) != EOF && i < MAXLEN) {
        if (c == ' ' || c == '\t') {
            delim_idx = i;
        }
        if (i == LINE_LEN) {
            if (delim_idx > 0) {
                delim_idx = print_line(line, delim_idx);
                move_to_start(line, delim_idx, i);
                i = i - delim_idx;
                delim_idx = 0;
            } else {
                print_line(line, i);
                i = 0;
                delim_idx = 0;
            }
        }
        if (c == '\n') {
            print_line(line, i);
            i = 0;
            delim_idx = 0;
        } else {
            line[i] = c;
            ++i;
        }
    }
    return 0;
}

int print_line(char line[], int i)
{
    char tmp = line[i + 1];
    line[i] = '\n';
    line[i + 1] = '\0';
    printf("%s", line);
    line[i + 1] = tmp;
    return i + 1;
}

void move_to_start(char line[], int from_idx, int len)
{
    int j;
    for (j = from_idx; j <= len; ++j) {
        line[j - from_idx] = line[j];
    }
}
