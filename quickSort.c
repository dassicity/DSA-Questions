#include <stdio.h>

int partition(int A[], int si, int ei)
{
    int count = 0, num = A[si], i, j, temp;

    for (i = si + 1; i <= ei; i++)
    {
        if (A[i] < num)
        {
            count++;
        }
    }

    A[si] = A[si + count];
    A[si + count] = num;

    for (i = si, j = ei; i<(si + count), j>(si + count);)
    {
        if (A[i] > num)
        {
            if (A[j] < num)
            {
                temp = A[i];
                A[i++] = A[j];
                A[j--] = temp;
            }
            else
            {
                j--;
            }
        }
        else if (A[j] < num)
        {
            if (A[i] > num)
            {
                temp = A[i];
                A[i++] = A[j];
                A[j--] = temp;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
            j--;
        }
    }
}

void quickSort(int A[], int si, int ei)
{
    int mid;
    if (si >= ei)
    {
        return;
    }

    mid = partition(A, si, ei);

    quickSort(A, si, mid - 1);
    quickSort(A, mid + 1, ei);
}

int main()
{
    int numbers[] = {3, 4, 9, 1, 2, 7, 4, 5}, i;

    quickSort(numbers, 0, 7);

    for (i = 0; i < 8; i++)
    {
        printf("%d ", numbers[i]);
    }
}