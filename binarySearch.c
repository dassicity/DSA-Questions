#include <stdio.h>

int binarySearch(int A[], int key, int size)
{
    int lower = 0, upper = (size - 1), mid, i = -1;

    while (upper >= lower)
    {
        mid = (upper + lower) / 2;
        if (key == A[mid])
        {
            i = mid;
            break;
        }
        else
        {
            if (key > A[mid])
            {
                lower = mid + 1;
            }
            else
            {
                upper = mid - 1;
            }
        }
    }

    return i;
}

int main()
{
    int numbers[10], i, number;
    printf("Enter the array of size 10: \n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Enter the number you want to search : \n");
    scanf("%d", &number);

    i = binarySearch(numbers, number, 10);

    if (i == -1)
    {
        printf("The number was not found.\n");
    }
    else
    {
        printf("The number was found at index %d\n", i + 1);
    }
}