#include <stdio.h>
#include <stdbool.h>

int f = 0, r = 1;

void printBfs(int size, int edges[][size], int sv, int e, bool visited[], int queue[])
{
    int i, currentIndex;
    queue[f] = sv;
    visited[sv] = true;

    // printf("%d -------------> ", sv);

    while (f != r)
    {
        currentIndex = queue[f++];
        printf("%d -------> ", currentIndex);

        for (i = 0; i < size; i++)
        {
            if (edges[currentIndex][i] == 1 && !visited[i])
            {
                queue[r++] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int edges[10][10];
    int i, j, e, start, end;
    bool visited[10];
    int queue[10];

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

    printBfs(10, edges, 0, e, visited, queue);

    return 0;
}