#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Functions for Minesweeper
//  void system(); No need for this because it is already in stdlib.h
char rb[9][9];
char mb[9][9];
int isValid(int row, int col)
{
   // Returns true if row number and column number
   // is in range
   return (row >= 0) && (row < 9) &&
          (col >= 0) && (col < 9);

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
// Functions for crossword
char a[5][5] = {{'_', '_', '_', '#', '#'},
                {'_', '#', '_', '#', '#'},
                {'_', '_', '_', '_', '_'},
                {'#', '#', '_', '#', '_'},
                {'#', '#', '_', '_', '_'}};
int b[5][5] = {
    {66, 65, 65, 35, 35},
    {85, 35, 76, 35, 35},
    {83, 79, 76, 73, 68},
    {35, 35, 79, 35, 79},
    {35, 35, 87, 73, 84},
};
int check()
{
   int count = 0;
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         if (a[i][j] != '_' && a[i][j] != '#')
            count++;
      }
   }
   if (count == 15)
   {
      return 0;
   }
   return -1;
}
void print()
{
   system("clear");
   printf("WELCOME TO CROSSWORD\n");
   printf("  1  2  3  4  5\n");
   printf("  -------------\n");
   printf("1|%c  %c  %c  %c  %c\n\n", a[0][0], a[0][1], a[0][2], a[0][3], a[0][4]);
   printf("2|%c  %c  %c  %c  %c\n\n", a[1][0], a[1][1], a[1][2], a[1][3], a[1][4]);
   printf("3|%c  %c  %c  %c  %c\n\n", a[2][0], a[2][1], a[2][2], a[2][3], a[2][4]);
   printf("4|%c  %c  %c  %c  %c\n\n", a[3][0], a[3][1], a[3][2], a[3][3], a[3][4]);
   printf("5|%c  %c  %c  %c  %c\n\n", a[4][0], a[4][1], a[4][2], a[4][3], a[4][4]);
   printf("\n\n\n\n");
   printf("Hints\n");
   printf("#            Direction              Row/Col             Clue\n");
   printf("1            Horizontal              1/1                Sheep Sound\n");
   printf("2            Horizontal              3/1                Neither Liquid nor gas\n");
   printf("3            Horizontal              5/3                Humor\n");
   printf("4             Vertical               1/1                Road Passenger Transport\n");
   printf("5             Vertical               1/3                To Permit\n");
   printf("6             Vertical               3/5                Point\n");
}
// FUNCTIONS FOR CHOMP
int n;
void glob()
{
   printf("Enter the size of grid\n");
   scanf("%d", &n);
}
char ab[40][40];
void inp()
{

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         ab[i][j] = 'X';
      }
   }
}
void printb()
{
   system("clear");
   printf("    WELCOME TO CHOMP\n");
   printf("    -----------------\n\n\n");
   for (int i = 1; i <= n; i++)
   {
      printf("     %d  ", i);
   }
   printf("\n     ");
   for (int i = 1; i <= n; i++)
   {
      printf("--------");
   }
   printf("\n");
   printf("\n");
   int k = 1;
   for (int i = 0; i < n; i++)
   {
      printf("%d|", k);
      k++;
      for (int j = 0; j < n; j++)
      {
         printf("    %c   ", ab[i][j]);
      }
      printf("\n\n\n");
   }
}
int checkb()
{
   if (ab[0][1] == '_' && ab[1][0] == '_' && ab[1][1] == '_')
   {
      return 1;
   }
   return -1;
}
int main()
{
   printf("___________________________________________WELCOME TO MINI-ARCADIA :) ___________________________________\n");
   printf("Enter 1 to play Chomp\n");
   printf("Enter 2 to play Crossword\n");
   printf("Enter 3 to play Minesweeper\n");
   int key;
   scanf("%d", &key);
   if (key == 1)
   {
      // void chomp();
      glob();
      inp();
      printb();
      int player = 1;
      while (1)
      {
         if (player % 2 == 0)
         {
            player = 2;
         }
         else
         {
            player = 1;
         }
         printf("Player %d please enter the row number and column number of the chocolate you want to eat\n", player);
         int i, j;
      labelb:
         scanf("%d%d", &i, &j);
         i = i - 1;
         j = j - 1;
         if (i == 0 && j == 0)
         {
            printf("You can not select the poisoned chocolate\n");
            printf("Please Select other value\n");
            goto labelb;
         }
         if (ab[i][j] == '_')
         {
            printf("That chocolate has already been selected\n");
            printf("Please Select other value\n");
            goto labelb;
         }
         for (int k = i; k < n; k++)
         {
            for (int l = j; l < n; l++)
            {
               ab[k][l] = '_';
            }
         }
         printb();
         int c = checkb();
         if (c == 1)
         {
            printf("Player %d is the winner\n", player);
            break;
         }
         player++;
      }
   }
   else if (key == 2)
   {
      // crossword();
      char d;
      print();
      while (1)
      {
         printf("Enter the row and column number of the entry which you want to make\n");
         int i, j;
      label:
         scanf("%d%d", &i, &j);
         i = i - 1;
         j = j - 1;
         if (a[i][j] == '#')
         {
            printf("You cannot enter the value at that place\n");
            printf("Choose another place\n");
            goto label;
         }
         else if (a[i][j] != '_')
         {
            printf("You have already entered the element for that place\n");
            printf("However if you want to change that press 'Y' or if you want to enter other value press'N'\n");
            char c;
            fflush(stdin);
            scanf("%c", &c);
            switch (c)
            {
            case 'Y':
            {
               printf("Enter the new value\n");
               char p;
               fflush(stdin);
               scanf("%c", &p);
               a[i][j] = p;
               break;
            }
            case 'N':
            {
               printf("Enter the new value of row and column number\n");
               goto label;
            }
            }
         }
         else
         {
            printf("Enter the character\n");
            fflush(stdin);
            scanf("%c", &d);
            a[i][j] = d;
         }
         print();
         if (check() == 0)
         {
            int f = 0;
            for (int i = 0; i < 5; i++)
            {
               for (int j = 0; j < 5; j++)
               {
                  if ((int)a[i][j] != b[i][j])
                  {
                     f = 1;
                  }
               }
            }
            if (f == 1)
            {
               printf("Your solution is wrong\n");
               printf("The correct soultion is:\n");
               printf("  1  2  3  4  5\n");
               printf("  -------------\n");
               printf("1|%c  %c  %c  %c  %c\n\n", (char)b[0][0], (char)b[0][1], (char)b[0][2], (char)b[0][3], (char)b[0][4]);
               printf("2|%c  %c  %c  %c  %c\n\n", (char)b[1][0], (char)b[1][1], (char)b[1][2], (char)b[1][3], (char)b[1][4]);
               printf("3|%c  %c  %c  %c  %c\n\n", (char)b[2][0], (char)b[2][1], (char)b[2][2], (char)b[2][3], (char)b[2][4]);
               printf("4|%c  %c  %c  %c  %c\n\n", (char)b[3][0], (char)b[3][1], (char)b[3][2], (char)b[3][3], (char)b[3][4]);
               printf("5|%c  %c  %c  %c  %c\n\n", (char)b[4][0], (char)b[4][1], (char)b[4][2], (char)b[4][3], (char)b[4][4]);
               break;
            }
            else
            {
               printf("Your solution is correct\n");
               break;
            }
         }
      }
   }
   else if (key == 3)
   {
      // Minesweeper
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
   }
   else
   {
      printf("Please enter a valid choice\n");
   }
   return 0;
}