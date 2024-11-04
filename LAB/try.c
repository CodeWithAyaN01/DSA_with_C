#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void tower(int num , char s , char t , char d)
{
    if (num == 1)
    {
        printf("\nMove disk 1 to %c to %c \n",s,d);
        return;
    }

    tower(num-1 , s , t , d);
    printf("Move disk %d from %c to %c",num,s,d);
    tower(num-1 , t , d , s);
    return;
}
int main()
{
    printf("\nEnter the number of disk : ");
    int num;
    scanf("%d",&num);
    printf("\nThe moves are involves are: ");
    tower(num,'A','C','B');
    getch();

}