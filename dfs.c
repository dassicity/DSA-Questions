#include <stdio.h>
#include <stdbool.h>

void printDfs(int size, int edges[][size], int sv, int e, bool visited[])
{
    int i;

    printf("%d ------> ", sv);
    visited[sv] = true;

    for (i = 0; i < size; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            printDfs(size, edges, i, e, visited);
        }
    }
}

int main()
{
    int edges[10][10];
    int i, j, e, start, end;
    bool visited[10];

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
        scanf("%d %d", &start, &end);
        edges[end][start] = edges[start][end] = 1;
    }

    for (i = 0; i < 10; i++)
    {
        visited[i] = false;
    }

    printDfs(10, edges, 0, e, visited);

    return 0;
}