#include<stdio.h>
char a[]={'0','1','2','3','4','5','6','7','8','9'};
void system();
int condition()
{
    if(a[1]==a[2] && a[2]==a[3] && a[3]==a[1])
    {
        return 1;
    }
    else if(a[4]==a[5] && a[5]==a[6] && a[6]==a[4])
    {
        return 1;
    }
    else if(a[7]==a[8] && a[9]==a[7] && a[7]==a[9])
    {
        return 1;
    }
    else if(a[1]==a[4] && a[4]==a[7] && a[7]==a[1])
    {
        return 1;
    }
    else if(a[2]==a[5] && a[5]==a[8] && a[8]==a[2])
    {
        return 1;
    }
    else if(a[3]==a[6] && a[6]==a[9] && a[3]==a[9])
    {
        return 1;
    }
    else if(a[1]==a[5] && a[9]==a[5] && a[9]==a[1])
    {
        return 1;
    }
    else if(a[3]==a[5] && a[5]==a[7] && a[7]==a[3])
    {
        return 1;
    }
    int c=0;
    for(int i=1;i<=9;i++)
    {
        if(a[i]=='X' || a[i]=='O')
        c++;
    }
    if(c==9)
    {
        return 0;
    }
    return -1;
}
void print()
{
    system("clear");
    printf("\n\n******  TIC TAC TOE  ******\n\n");
    printf("       |        |       \n");
    printf("   %c   |   %c    |  %c  \n",a[1],a[2],a[3]);
    printf("_______|________|_______\n");
    printf("       |        |       \n");
    printf("   %c   |   %c    |  %c  \n",a[4],a[5],a[6]);
    printf("_______|________|_______\n");
    printf("       |        |       \n");
    printf("   %c   |   %c    |  %c  \n",a[7],a[8],a[9]);
    printf("       |        |       \n");
}
int main()
{
    print();
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
    char s=(player==1?'X':'O');
    printf("Player %d choose any number you want to replace\n",player);
    int i;
    label:
    scanf("%d",&i);
    if(a[i]=='X' || a[i]=='O')
    {
        printf("That number has already been selected\n");
        printf("Please Select another number\n");
        goto label;
    }
    if(i>=1 && i<=9)
    {
    a[i]=s;
    print();
    }
    else
    {
        printf("Wrong input\n");
        printf("Please Select a valid input\n");
        goto label;
    }
    int c=condition();
    if(c==1)
    {
        printf("The winner is player %d\n",player);
        break;
    }
    else if(c==0)
    {
        printf("The match is a draw\n" );
        break;
    }
    player++;
    }
    return 0;
}