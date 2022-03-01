#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("signed char %d %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char %d %d\n", 0, UCHAR_MAX);
    printf("char %d %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed short int %d %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int %d %d\n", INT_MIN, INT_MAX);
    printf("unsigned int %d %u\n", 0, UINT_MAX);
    printf("signed long int %ld %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int %d %lu\n", 0, ULONG_MAX);
    printf("\n");
    printf("float %f %f\n", FLT_MIN, FLT_MAX);
    printf("double %f %f\n", DBL_MIN, DBL_MAX);
    return 0;
}
