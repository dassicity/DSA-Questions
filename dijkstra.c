#include <stdio.h>
#include <stdbool.h>

void dijkstraPath(int size, int edges[][size], bool visited[], int parent[], int weights[], int sv)
{

    int i = 0;
    visited[sv] = true;

    if (sv >= size)
    {
        return;
    }

    for (i = 0; i < size; i++)
    {
        if (edges[sv][i] != 0 && !visited[i])
        {
            if (weights[i] > edges[sv][i])
            {
                weights[i] = edges[sv][i] + weights[sv];
                parent[i] = sv;
            }
        }
    }

    sv++;
    for (i = 0; i < size; i++)
    {
        if (!visited[i] && weights[i] < weights[sv])
        {
            sv = i;
        }
    }
    dijkstraPath(size, edges, visited, parent, weights, sv);
}

int main()
{
    int edges[10][10];
    int i, j, e, start, end, weight;
    bool visited[10];
    int parent[10], weights[10];

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            edges[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // printf("%d", e);

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &start, &end, &weight);
        edges[end][start] = edges[start][end] = weight;
    }

    for (i = 0; i < 10; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        weights[i] = 30000;
    }
    weights[0] = 0;
    dijkstraPath(10, edges, visited, parent, weights, 0);

    for (i = 0; i < 10; i++)
    {
        if (weights[i] < 30000)
        {
            printf("%d---%d w = %d\n", parent[i], i, weights[i]);
        }
    }

    return 0;
}