#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
    int i;
    int v[] = {1, 15, 7, 2, 3, 1, 14};
    int n = 7;
    shellsort(v, n);
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    putchar('\n');
    return 0;
}

/* shellsort: sorting v[0] ... v[n-1] in ascending order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}
