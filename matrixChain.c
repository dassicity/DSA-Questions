#include <stdio.h>
#include <limits.h>
int matrixChain(int A[], int start, int end)
{
    int i, count, min = INT_MAX;

    if (start == end)
    {
        return 0;
    }

    for (i = start; i <= (end - 1); i++)
    {
        count = matrixChain(A, start, i) + matrixChain(A, i + 1, end) + (A[start - 1] * A[i] * A[end]);

        if (count < min)
        {
            min = count;
        }
    }
    return min;
}

int main()
{
    int A[10], size, i, ops;

    printf("Enter the number of matrices: \n");
    scanf("%d", &size);

    printf("Enter %d integers: \n", size + 1);

    for (i = 0; i <= size; i++)
    {
        scanf("%d", &A[i]);
    }

    ops = matrixChain(A, 1, size);

    printf("Number of operations are: %d\n", ops);

    return 0;
}