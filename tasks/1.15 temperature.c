#include <stdio.h>

float fahrenheit_to_celsius(int fahr);

float fahrenheit_to_celsius(int fahr)
{
    return (5.0  / 9.0) * (fahr - 32.0);
}

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
    printf("Temperature table of Fahrenheit and Celsius\n");
    printf("-------------\n");
    while (fahr <= upper) {
        celsius = fahrenheit_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}