#include <stdio.h>
#include <stdbool.h>

void sort(int size, float ratio[], float cost[], float weights[])
{
    int i, j;
    float temp;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (ratio[i] > ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = cost[i];
                cost[i] = cost[j];
                cost[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }
}

int knapSack(int size, float costs[], float weights[], float ratio[], int capacity, float sack[])
{
    int weight = 0, i, temp;

    for (i = 0; i < size; i++)
    {
        if (weight < capacity)
        {
            if (weight + weights[i] > capacity)
            {
                temp = capacity - weight;
                sack[i] = temp * ratio[i];
                weight = capacity;
            }
            else
            {
                weight = weight + weights[i];
                sack[i] = costs[i];
            }
        }
    }

    return weight;
}

int main()
{
    int capacity, i, weight;
    float ratio[5], costs[5], weights[5], sack[5];
    printf("Enter the costs and their weights: \n");

    for (i = 0; i < 5; i++)
    {
        scanf("%f %f", &costs[i], &weights[i]);
        ratio[i] = costs[i] / weights[i];
    }

    printf("Enter the capacity : ");
    scanf("%d", &capacity);
    sort(5, ratio, costs, weights);
    weight = knapSack(5, costs, weights, ratio, capacity, sack);

    printf("%d \n", weight);
    for (i = 0; i < 5; i++)
    {
        printf("%f\n", sack[i]);
    }

    return 0;
}