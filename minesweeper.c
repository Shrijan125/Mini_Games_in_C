#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// void system(); No need for this because it is already in stdlib.h
char rb[9][9];
char mb[9][9];
int isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < 9) &&
           (col >= 0) && (col < 9);
}
int isMine(int row, int col, char board[9][9])
{
    if (board[row][col] == '*')
        return (1);
    else
        return (0);
}
// Setting all the elements of mb to '-'
void initialize(char a[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            a[i][j] = '-';
        }
    }
}
// Printing the board
void printm(char a[9][9])
{
    system("clear");
    printf("                      WELCOME TO MINESWEEPER          \n\n\n");
    for (int i = 1; i <= 9; i++)
    {
        printf("     %d  ", i);
    }
    printf("\n");
    printf("   -------------------------------------------------------------------\n\n");
    int k = 1;
    for (int i = 0; i < 9; i++)
    {
        printf("%d|", k);
        k++;
        for (int j = 0; j < 9; j++)
        {
            printf("   %c    ", a[i][j]);
        }
        printf("\n\n\n");
    }
}
// Setting the real board with mines
void srb(char a[9][9])
{
    srand(time(NULL));
    int d = 0;
    while (1)
    {
        int r = rand() % 9;
        int c = rand() % 9;
        if (a[r][c] != '*')
        {
            a[r][c] = '*';
            d++;
        }
        if (d == 10)
        {
            break;
        }
    }
}
// Generating and setting the numbers
void num(char realBoard[9][9])
{
    int row, col, count;
    for (row = 0; row < 9; row++)
    {

        for (col = 0; col < 9; col++)
        {
            count = 0;
            if (realBoard[row][col] != '*')
            {

                if (isValid(row - 1, col) == 1)
                {
                    if (isMine(row - 1, col, realBoard) == 1)
                        count++;
                }
                if (isValid(row + 1, col) == 1)
                {
                    if (isMine(row + 1, col, realBoard) == 1)
                        count++;
                }
                if (isValid(row, col + 1) == 1)
                {
                    if (isMine(row, col + 1, realBoard) == 1)
                        count++;
                }
                if (isValid(row, col - 1) == 1)
                {
                    if (isMine(row, col - 1, realBoard) == 1)
                        count++;
                }
                if (isValid(row - 1, col + 1) == 1)
                {
                    if (isMine(row - 1, col + 1, realBoard) == 1)
                        count++;
                }
                if (isValid(row - 1, col - 1) == 1)
                {
                    if (isMine(row - 1, col - 1, realBoard) == 1)
                        count++;
                }
                if (isValid(row + 1, col + 1) == 1)
                {
                    if (isMine(row + 1, col + 1, realBoard) == 1)
                        count++;
                }
                if (isValid(row + 1, col - 1) == 1)
                {
                    if (isMine(row + 1, col - 1, realBoard) == 1)
                        count++;
                }
                realBoard[row][col] = count + '0';
            }
        }
    }
}
void rec(int row, int col)
{
    if (rb[row][col] == '*')
    {
        return;
    }
    if (rb[row][col] != '0' && isValid(row, col) == 1)
    {
        mb[row][col] = rb[row][col];
        return;
    }
    if (mb[row][col] == '0')
    {
        return;
    }
    mb[row][col] = rb[row][col];
    if (isValid(row - 1, col) == 1)
    {
        rec(row - 1, col);
    }
    if (isValid(row + 1, col) == 1)
    {
        rec(row + 1, col);
    }
    if (isValid(row, col + 1) == 1)
    {
        rec(row, col + 1);
    }
    if (isValid(row, col - 1) == 1)
    {
        rec(row, col - 1);
    }
    if (isValid(row - 1, col + 1) == 1)
    {
        rec(row - 1, col + 1);
    }
    if (isValid(row - 1, col - 1) == 1)
    {
        rec(row - 1, col - 1);
    }
    if (isValid(row + 1, col + 1) == 1)
    {
        rec(row + 1, col + 1);
    }
    if (isValid(row + 1, col - 1) == 1)
    {
        rec(row + 1, col - 1);
    }
}
int win()
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mb[i][j] != '-')
            {
                count++;
            }
        }
    }
    if (count == 71)
    {
        return 1;
    }
    return -1;
}
int main()
{
    initialize(mb);
    srb(rb);
    num(rb);
    printf("\n\n\n");
    printm(mb);
    while (1)
    {
        int x, y;
        printf("Enter the x and y coordinates of the cell\n");
        scanf("%d%d", &x, &y);
        x = x - 1;
        y = y - 1;
        if (rb[x][y] == '*')
        {
            mb[x][y] = '*';
            printm(mb);
            printf("You lost the match\n");
            break;
        }
        else if (rb[x][y] != '0')
        {
            mb[x][y] = rb[x][y];
            printm(mb);
        }
        else if (rb[x][y] == '0')
        {
            rec(x, y);
            printm(mb);
        }
        if (win() == 1)
        {
            printf("You won the match\n");
            break;
        }
    }
    return 0;
}
