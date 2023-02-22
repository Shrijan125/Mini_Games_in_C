#include<stdio.h>
void system();
int n;
void glob()
{
    printf("Enter the size of grid\n");
    scanf("%d",&n);
}
char ab[40][40];
void inp()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           ab[i][j]='X';
        }
    }
}
void printb()
{
    system("clear");
    printf("    WELCOME TO CHOMP\n");
    printf("     ----------------\n\n\n");
    for(int i=1;i<=n;i++)
    {
    printf("     %d  ",i);
    }
    printf("\n     ");
    for(int i=1;i<=n;i++)
    { 
        printf("--------");
    }
    printf("\n");
    printf("\n");
    int k=1;
    for(int i=0;i<n;i++)
    {
        printf("%d|",k);
        k++;
        for(int j=0;j<n;j++)
        {
            printf("    %c   ",ab[i][j]);
        }
        printf("\n\n\n");
    }
}
int checkb()
{
    if(ab[0][1]=='_'&&ab[1][0]=='_'&&ab[1][1]=='_')
    {
        return 1;
    }
    return -1;
}
int main()
{
    glob();
    inp();
    printb();
    int player=1;   
    while(1)
    {
        if(player%2==0)
        {
            player=2;
        }
        else
        {
            player=1;
        }
        printf("Player %d please enter the row number and column number of the chocolate you want to eat\n",player);
        int i,j;
        labelb:
        scanf("%d%d",&i,&j);
        i=i-1;
        j=j-1;
        if(i==0 && j==0)
        {
            printf("You can not select the poisoned chocolate\n");
            printf("Please Select other value\n");
            goto labelb;
        }
        if(ab[i][j]=='_')
        {
            printf("That chocolate has already been selected\n");
            printf("Please Select other value\n");
            goto labelb;
        }
        for(int k=i;k<n;k++)
        {
            for(int l=j;l<n;l++)
            {
                ab[k][l]='_';
            }
        }
        printb();
        int c=checkb();
        if(c==1)
        {
            printf("Player %d is the winner\n",player);
            break;
        }
        player++;
    }
    return 0;
}