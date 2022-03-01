#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    double num;
    char s[] = "123.456e-6";
    num = atof(s);
    printf("%f\n", num);
    printf("%e\n", num);
    return 0;
}

double atof(char s[])
{
    double val, power, e_base;
    int i, sign, e_power, e_iter;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        e_base = (s[i] == '-') ? 10.0 : 0.1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (e_power = 0; isdigit(s[i]); i++)
            e_power = 10 * e_power + (s[i] - '0');
        for (e_iter = 0; e_iter < e_power; e_iter++)
            power *= e_base;
    }
    return sign * val / power;
}
