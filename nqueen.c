#include <stdio.h>
#include <stdbool.h>

int board[8][8], count = 1;

void printBoard(int size, int board[][size])
{
    int i, j;
    printf("Solution number : %d\n", count++);
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

bool isValid(int size, int board[][size], int row, int col)
{
    int i, j;

    for (i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    for (i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void nqueen(int size, int board[][size], int row)
{
    int i, j;
    // printf("%d\n", row);

    if (row == size)
    {
        printBoard(size, board);
        return;
    }

    for (j = 0; j < size; j++)
    {
        // printf("Valid = %d\n", isValid(board, row, j));
        if (isValid(size, board, row, j))
        {

            board[row][j] = 1;
            // printf("%d\n", board[row][j]);
            // printBoard(board);
            nqueen(size, board, row + 1);
            board[row][j] = 0;
        }
    }
}

int main()
{
    // int board[4][4];
    int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }

    nqueen(8, board, 0);

    return 0;
}