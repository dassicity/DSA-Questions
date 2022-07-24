#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int cost = INT_MAX;
int min(int A, int B)
{
    return (A >= B ? A : B);
}

int tsp(int size, int startVertex, bool visited[], int graph[][size])
{
    int i, temp;

    visited[startVertex] = true;
    for (i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            // visited[i] = true;
            temp = graph[startVertex][i] + tsp(size, i, visited, graph);
            if (i == startVertex)
            {
                if (temp < cost)
                {
                    cost = temp;
                }
            }
            else
            {
                cost = graph[startVertex][i];
            }
        }
    }

    visited[startVertex] = false;

    return cost;
}

int main()
{
    int v, graph[10][10], i, j, cost;
    bool visited[10];

    printf("Enter the number of vertices: \n");
    scanf("%d", &v);

    for (i = 0; i < v; i++)
    {
        visited[i] = false;
        for (j = 0; j < v; j++)
        {
            printf("Enter value at Graph[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    cost = tsp(v, 0, visited, graph);

    printf("%d\n", cost);

    return 0;
}