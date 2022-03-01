#include <stdio.h>

#define MAXLEN 1000

void escape(char s[], char t[], int lim);
void unescape(char s[], char t[]);
char unescape_char(char c);

int main()
{
    int i, c;
    char s[MAXLEN], t[MAXLEN];
    i = 0;
    while ((c = getchar()) != EOF && i < MAXLEN) {
        t[i] = c;
        ++i;
    }
    escape(s, t, MAXLEN);
    printf("%s\n", s);
    unescape(t, s);
    printf("%s\n", t);
    return 0;
}

void escape(char s[], char t[], int lim)
{
    int i, j;
    for (i = j = 0; j < lim && t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\t':
            s[j] = '\\';
            s[++j] = 't';
            break;
        case '\n':
            s[j] = '\\';
            s[++j] = 'n';
            break;
        default:
            s[j] = t[i];
            break;
        }
        ++j;
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j, esc;
    esc = 0;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\\':
            esc = 1;
            s[j++] = t[i];
            break;
        case 't': case 'n':
            if (esc) {
                s[j - 1] = unescape_char(t[i]);
            } else {
                s[j++] = t[i];
            }
            esc = 0;
            break;
        default:
            s[j++] = t[i];
            esc = 0;
            break;
        }
    }
}

char unescape_char(char c)
{
    switch (c) {
    case 't':
        return '\t';
    case 'n':
        return '\n';
    default:
        return c;
    }
}
