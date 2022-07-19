#include <stdio.h>

void merge(int A[], int lower1, int upper1, int lower2, int upper2)
{
    int p = lower1, q = lower2;
    int temp = 0, Arr[100], i = 0;
    // printf("lower1 = %d\n", A[lower1]);
    // printf("upper1 = %d\n", A[upper1]);
    // printf("lower2 = %d\n", A[lower2]);
    // printf("upper2 = %d\n", A[upper2]);

    while (lower1 <= upper1 && lower2 <= upper2)
    {
        // if (A[lower1] < A[lower2])
        // {
        //     Arr[i++] = A[lower1];
        //     lower1++;
        // }
        // else if (A[lower1] > A[lower2])
        // {
        //     Arr[i++] = A[lower2];
        //     lower2++;
        // }
        // else
        // {
        //     Arr[i++] = A[lower1];
        //     Arr[i++] = A[lower2];
        // }
        // i++;

        Arr[i++] = (A[lower1] < A[lower2]) ? A[lower1++] : A[lower2++];
    }

    while (lower1 <= upper1)
    {
        Arr[i] = A[lower1];
        lower1++;
        i++;
    }

    while (lower2 <= upper2)
    {
        Arr[i] = A[lower2];
        lower2++;
        i++;
    }

    for (i = p; i <= upper1; i++)
    {
        A[i] = Arr[temp++];
    }

    for (i = q; i <= upper2; i++)
    {
        A[i] = Arr[temp++];
    }
}

void mergeSort(int A[], int si, int ei)
{
    int mid;
    // printf("si = %d\n", si);
    // printf("ei = %d\n", ei);
    if (si >= ei)
    {
        return;
    }

    mid = (si + ei) / 2;
    // printf("mid = %d\n", mid);

    mergeSort(A, si, mid);
    mergeSort(A, mid + 1, ei);
    merge(A, si, mid, mid + 1, ei);
}

int main()
{
    int numbers[] = {4, 12, 9, 3, 3, 98, 54};
    int i;
    mergeSort(numbers, 0, 6);

    for (i = 0; i < 7; i++)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}