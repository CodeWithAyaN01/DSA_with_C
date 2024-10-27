// Circular Queue ;
#include<stdio.h>
#include<conio.h>
#define max 5
char que[max];
int rear=-1,front=0,count=0;
void insert(char elem)
{
    if (count == max)
    {
        printf("Que overflow: ");
    }
    else
    {
        rear = (rear+1) %max;
        que[rear] = elem;
        count++;
    }
}
void del()
{
    if (count == 0)
    {
        printf("Que underflwo: ");
    }
    else
    {
        printf("Deleted elem is %c",que[front]);
        front = (front+1) % max;
        count--;
    }
}
void dis()
{
    int c,i;
    printf("Que is \n");
    i= front;
    for (c = 1 ; c<=count ; c++)
    {
        printf("%c \t",que[i]);
        i = (i+1)%max;
    }
}
void main()
{
    int choose;
    int element;
    printf("'Enter choice\n'");
     printf("\n Enter 1:insert\t Enter 2:delete\t Enter 3:display\t Enter 4:exit\t");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1 : printf("ENter elem: ");
            element = getche();
            insert(element);
        break;
    
    default:
        break;
    }
}