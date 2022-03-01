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

// potentially this implementation will require less comparisons
// when the x number is greater than mid and the length of array
// is big.
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid;
        else
            low = mid;
    }
    if (v[low] == x) {
        return low;
    }
    if (v[high] == x) {
        return high;
    }
    return -1;
}
