#include <stdio.h>
#include <stdlib.h>
int Position(int *a, int lb, int ub)
{
    int pivot = a[lb], temp, start = lb, end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (pivot < a[end])
        {
            end--;
        }
        if (start < end)
        {
            // swap a[start], a[end]
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    // swap a[lb], a[end]
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void Quicksort(int *a, int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = Position(a, lb, ub);
        Quicksort(a, lb, loc - 1);
        Quicksort(a, loc + 1, ub);
    }
}
int main()
{
    int a[] = {7, 6, 10, 88, 9, 1, 15, 7}, lb = 0, ub = sizeof(a) / sizeof(a[0]) - 1;
    Quicksort(a, lb, ub);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
