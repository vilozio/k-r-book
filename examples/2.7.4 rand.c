#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

int main()
{
    srand(1234);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
}


unsigned long int next = 1;

/* rand: returns pseudo-random number 0...32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

/* srand: set "seed" for rand() */
void srand(unsigned int seed)
{
    next = seed;
}
