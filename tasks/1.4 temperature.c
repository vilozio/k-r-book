#include <stdio.h>
/* Print table of temperature with Fahrenheit
and Celsius scale for fahr = 0, 20, ..., 300 */
int main()
{
    float celsius, fahr;
    int lower, upper, step;
    lower = 0; /* lower bound of temperature table */
    upper = 300; /* upper bound */
    step = 20; /* step */
    celsius = lower;
    printf("Temperature table of Celsius and Fahrenheit\n");
    printf("-------------\n");
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}