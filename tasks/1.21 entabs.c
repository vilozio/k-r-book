#include <stdio.h>

#define MAXCHARS 10000
#define MAXLEN 1000
#define TAB_LEN 4

int remove_char(char line[], int len, char c);
int idx_column_width(int i);
int entab(char line[], int len);
int get_input_line(char line[], int lim);
void copy(char to[], char from[], int to_shift, int len, int lim);

int main()
{
    int len;
    char all_chars[MAXCHARS];
    char line[MAXLEN];
    int to_shift = 0;
    while ((len = get_input_line(line, MAXLEN)) > 0) {
        len = entab(line, len);
        copy(all_chars, line, to_shift, len, MAXCHARS);
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

int remove_char(char line[], int len, char c)
{
    int i;
    int cutoff = 0;
    for (i = 0; i <= len; ++i) {
        if (line[i] == c) {
            ++cutoff;
        } else {
            line[i - cutoff] = line[i];
        }
    }
    return len - cutoff;
}

int idx_column_width(int i)
{
    int width;
    if (i < TAB_LEN) {
        width = TAB_LEN - i;
    } else {
        width = TAB_LEN - (i % TAB_LEN);
    }
    return width;
}

int entab(char line[], int len)
{
    int i, line_width;
    char empty_char = '\0';
    int space_seq = 0;
    line_width = 0;
    for (i = 0; i <= len; ++i) {
        if (line[i] == '\t') {
            line_width += idx_column_width(i) - 1;
        }
        if (line[i] == ' ') {
            ++space_seq;
        } else {
            space_seq = 0;
        }
        if (idx_column_width(line_width) == TAB_LEN) {
            if (space_seq == TAB_LEN) {
                line[i - space_seq - 1] = '\t';
                --space_seq;
                while (space_seq > 0) {
                    line[i - space_seq - 1] = empty_char;
                    --space_seq;
                }
            } else {
                space_seq = 0;
            }
        }
        ++line_width;
    }
    len = remove_char(line, len, empty_char);
    return len;
}

int get_input_line(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
    }
    return i;
}

void copy(char to[], char from[], int to_shift, int len, int lim)
{
    int i;
    i = 0;
    while ((to_shift + i < lim - 1) && i <= len) {
        to[to_shift + i] = from[i];
        ++i;
    }
}
