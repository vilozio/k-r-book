#include <stdio.h>

int my_strlen(char *s);

int main()
{
    int n1, n2, n3;
    char array[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *ptr = array;
    n1 = my_strlen("Hello, world!");
    n2 = my_strlen(array);
    n3 = my_strlen(ptr);
    printf("%d %d %d", n1, n2, n3);
}

/* strlen: returns the length of the string */
int my_strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0' ; s++)
        n++;
    return n;
}