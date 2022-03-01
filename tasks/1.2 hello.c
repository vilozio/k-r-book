#include <stdio.h>

int main() {
    printf("Hello, world!\n\c");
    return 0;
}

// /path/k-r-book/tasks/1.2 task.c: In function ‘main’:
// /path/k-r-book/tasks/1.2 task.c:4:12: warning: unknown escape sequence: '\c'
//      printf("Hello, world!\n\c");
//             ^~~~~~~~~~~~~~~~~~~
// Hello, world!
// c
