#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0; /* next free position in stack */
double val[MAXVAL]; /* stack */

/* push: put value f in stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, not enough space for %g\n", f);
}

/* pop: take a value from top of the stack and return it */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}
