#include <stdio.h>
/* Print table of temperature with Fahrenheit
and Celsius scale for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; /* lower bound of temperature table */
    upper = 300; /* upper bound */
    step = 20; /* step */
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0  / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}