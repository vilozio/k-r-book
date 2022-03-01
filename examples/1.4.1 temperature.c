#include <stdio.h>

#define LOWER 0 /* lower bound of table */
#define UPPER 300 /* upper bound */
#define STEP 20 /* step size */

/* Print table of temperature with Fahrenheit and Celsius */
int main ()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}
