#include <stdio.h>

#define MAXCHARS 10000
#define MAXLEN 1000
#define TAB_LEN 4

int replace_tab(char line[], int i, int lim);
int get_replace_tabs_line(char line[], int lim);
void copy(char to[], char from[], int to_shift, int lim);

int main()
{
    int len;
    char all_chars[MAXCHARS];
    char line[MAXLEN];
    int to_shift = 0;
    while ((len = get_replace_tabs_line(line, MAXLEN)) > 0) {
        copy(all_chars, line, to_shift, MAXCHARS);
        to_shift += len + 1;
        if (to_shift > MAXCHARS - 1) {
            to_shift = MAXCHARS - 1;
        }
    }
    if (to_shift > 0) {
        all_chars[to_shift] = '\0';
        printf("\n%s\n", all_chars);
    }
    return 0;
}

// not in use, just an example
// int shift_chars(char line[], char new_line[], int len, char c)
// {
//     int i = 0;
//     int j = 0;
//     while (i <= len && j <= len) {
//         new_line[j] = line[i];
//         if (line[i] == c) {
//             ++j;
//             new_line[j] = c;
//         }
//         ++i;
//         ++j;
//     }
// }

int replace_tab(char line[], int i, int lim)
{
    int spaces;
    if (i < TAB_LEN) {
        spaces = TAB_LEN - i;
    } else {
        spaces = TAB_LEN - (i % TAB_LEN);
    }
    line[i] = ' ';
    --spaces;
    while (spaces > 0 && i < lim - 1) {
        ++i;
        line[i] = ' ';
        --spaces;
    }
    return i;
}

int get_replace_tabs_line(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            i = replace_tab(line, i, lim);
        } else {
            line[i] = c;
        }
    }
    if (c == '\n') {
        line[i] = c;
    }
    return i;
}

void copy(char to[], char from[], int to_shift, int lim)
{
    int i;
    i = 0;
    while ((to_shift + i < lim - 1) && ((to[to_shift + i] = from[i]) != '\0'))
        ++i;
}
