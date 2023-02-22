#include<stdio.h>
void system();
char a[5][5]={{'_','_','_','#','#'},
              {'_','#','_','#','#'},
              {'_','_','_','_','_'},
              {'#','#','_','#','_'},
              {'#','#','_','_','_'}};
int b[5][5]={{66,65,65,35,35},
             {85,35,76,35,35},
             {83,79,76,73,68},
             {35,35,79,35,79},
             {35,35,87,73,84},};
int check()
{
    int count=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]!='_' && a[i][j]!='#')
            count ++;
        }
    }
    if(count==15)
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
    printf("1|%c  %c  %c  %c  %c\n\n",a[0][0],a[0][1],a[0][2],a[0][3],a[0][4]);
    printf("2|%c  %c  %c  %c  %c\n\n",a[1][0],a[1][1],a[1][2],a[1][3],a[1][4]);
    printf("3|%c  %c  %c  %c  %c\n\n",a[2][0],a[2][1],a[2][2],a[2][3],a[2][4]);
    printf("4|%c  %c  %c  %c  %c\n\n",a[3][0],a[3][1],a[3][2],a[3][3],a[3][4]);
    printf("5|%c  %c  %c  %c  %c\n\n",a[4][0],a[4][1],a[4][2],a[4][3],a[4][4]);
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
int main()
{
    char d;
    print();
    while(1)
    {
        printf("Enter the row and column number of the entry which you want to make\n");
        int i,j;
        label:
        scanf("%d%d",&i,&j);
        i=i-1;
        j=j-1;
        if(a[i][j]=='#')
        {
            printf("You cannot enter the value at that place\n");
            printf("Choose another place\n");
            goto label;
        }
        else  if(a[i][j]!='_')
        {
            printf("You have already entered the element for that place\n");
            printf("However if you want to change that press 'Y' or if you want to enter other value press'N'\n");
            char c;
            fflush(stdin);
            scanf("%c",&c);
            switch(c)
            {
                case 'Y':
                {
                    printf("Enter the new value\n");
                    char p;
                    fflush(stdin);
                    scanf("%c",&p);
                    a[i][j]=p;
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
            scanf("%c",&d);
            a[i][j]=d;
        }
        print();
        if(check()==0)
        {
            int f=0;
            for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                        {
                            if((int)a[i][j]!=b[i][j])
                            {
                                f=1;
                            }
                        }
                }
            if(f==1)
            {
                printf("Your solution is wrong\n");
                printf("The correct soultion is:\n");
                printf("  1  2  3  4  5\n");
                printf("  -------------\n");
                printf("1|%c  %c  %c  %c  %c\n\n",(char)b[0][0],(char)b[0][1],(char)b[0][2],(char)b[0][3],(char)b[0][4]);
                printf("2|%c  %c  %c  %c  %c\n\n",(char)b[1][0],(char)b[1][1],(char)b[1][2],(char)b[1][3],(char)b[1][4]);
                printf("3|%c  %c  %c  %c  %c\n\n",(char)b[2][0],(char)b[2][1],(char)b[2][2],(char)b[2][3],(char)b[2][4]);
                printf("4|%c  %c  %c  %c  %c\n\n",(char)b[3][0],(char)b[3][1],(char)b[3][2],(char)b[3][3],(char)b[3][4]);
                printf("5|%c  %c  %c  %c  %c\n\n",(char)b[4][0],(char)b[4][1],(char)b[4][2],(char)b[4][3],(char)b[4][4]);
                break;
            }
            else
            {
                printf("Your solution is correct\n");
                break;
            }
        }
    }
    return 0;
}