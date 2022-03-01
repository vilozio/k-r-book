#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int n = 10;
    int v[n];
    for (int i = 0; i < n; i++)
        v[i] = i;
    printf("%d\n", binsearch(3, v, n));
    return 0;
}

/* binsearch: find х in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* match found */
            return mid;
    }
    return -1; /* no match */
}
