#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
    int a[] = {1, 15, 6, 2, 5, 17, 0};
    qsort(a, 0, 6);
    for (int i = 0; i <= 6; i++)
        printf("%d ", a[i]);
    return 0;
}

/* qsort: sorts v[left]...v[right] in ascending order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) /* do nothing if */
        return;        /* the array has less than two elements */
    swap(v, left, (left + right) / 2); /* dividing element */
    last = left;                       /* moves to v[0] */
    for(i = left + 1; i <= right; i++) /* division in parts */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last); /* new dividing element */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: swap two elements v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
