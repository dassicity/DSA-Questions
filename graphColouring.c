#include <stdio.h>
#include <stdbool.h>

void printBoard(int size, int board[size][size])
{
    int i, j;
    // printf("Solution number : %d\n", count++);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

bool isValid(int size, int edges[][size], int colour, int vertex)
{
    int i;

    if (vertex == 0)
    {
        return true;
    }

    for (i = 0; i < size; i++)
    {
        if (edges[vertex][i] == 0)
        {
            if (edges[i][i] == colour)
            {
                return false;
            }
        }
    }
    return true;
}

void colour(int size, int edges[][size], int vertex, int colours)
{
    int i;

    if (vertex == size)
    {
        // print
        for (i = 0; i < size; i++)
        {
            printf("%d --- > ", edges[i][i]);
        }
        printf("\n");
        return;
    }

    for (i = 1; i <= colours; i++)
    {
        if (isValid(size, edges, i, vertex))
        {
            edges[vertex][vertex] = i;
            // printBoard(size, edges);
            colour(size, edges, vertex + 1, colours);
            edges[vertex][vertex] = 0;
        }
    }
}

int main()
{
    int edges[4][4];
    int i, j, e, start, end, colours;
    bool visited[10];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            edges[i][j] = -1;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // printf("%d", e);

    for (i = 0; i < e; i++)
    {
        scanf("%d", &start);
        scanf("%d", &end);
        edges[end][start] = 0;
        edges[start][end] = 0;
        // printf("one = %d other = %d\n", edges[start][end], edges[end][start]);
    }

    // printBoard(e, edges);

    printf("Enter the number of colours: \n");
    scanf("%d", &colours);

    colour(e, edges, 0, colours);

    return 0;
}