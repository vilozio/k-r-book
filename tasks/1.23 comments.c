#include <stdio.h>

#define COMMENT_MAYBE 1
#define COMMENT_FOUND 2

int main()
{
    int c;
    int start_str = 0;
    int start_char = 0;
    int is_esc = 0;
    int start_co = 0;
    int one_line_co = 0;
    int end_co = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\\') {
            ++is_esc;
        }
        if (c == '\"' && is_esc % 2 == 0) {
            start_str = !start_str;
        } else if (c == '\'' && is_esc % 2 == 0) {
            start_char = !start_char;
        } else {
            is_esc = 0;
        }
        if (c == '/' && !start_str && !start_char && !start_co) {
            ++start_co;
        }
        if ((c == '*' || c == '/') && start_co == COMMENT_MAYBE) {
            ++start_co;
            if (c == '/') {
                one_line_co = 1;
            }
        } else if (start_co == COMMENT_MAYBE) {
            putchar('/');
            start_co = 0;
        }
        if (one_line_co && c == '\n') {
            start_co = 0;
            one_line_co = 0;
        }
        if (start_co >= COMMENT_FOUND && !one_line_co) {
            if (c == '*') {
                ++end_co;
            } else if (end_co == COMMENT_MAYBE && c == '/') {
                start_co = 0;
                end_co = 0;
            } else {
                end_co = 0;
            }
        }
        if (start_co == 0) {
            putchar(c);
        }
    }
    return 0;
}
