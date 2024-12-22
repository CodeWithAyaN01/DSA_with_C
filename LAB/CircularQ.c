// Circular Queue ;
#include<stdio.h>
#include<conio.h>
#define max 5
char que[max];
int rear=-1,front=0,count=0;
void insert(char elem) 
{
    if(count==max)
        printf("\n Queue overflow");
    else 
    {
        rear=(rear+1) % max;
        que[rear]=elem;
        count++;
    }
}
void del()
{
    if(count==0)
        printf("\n Queue underflow");
    else 
    {
        printf("\n The deleted element is %c",que[front]);
        front=(front+1)%max;
        count--;
    }
}
void display() 
{
    int i,c;
    if(count==0)
    printf("\n Queue is empty");
    else 
    {
        i=front;
        for(c=1;c<=count;c++) 
        {
            printf("%c\t",que[i]);
            i=(i+1)%max;
        }
    }   
}
int main() 
{
    int choice;
    char element;
    char nn;
    while(1)
    {
        printf("\n Enter 1:insert\t Enter 2:delete\t Enter 3:display\t Enter 4:exit\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter the element: ");
                    // fflush(stdin);
                    // element=getchar();
                    scanf(" %c",&element); // exact 
                    insert(element);
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
        }
    }
}