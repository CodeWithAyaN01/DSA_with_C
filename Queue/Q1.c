#include<stdio.h>
#define size 10
int Que[size];
int front = -1;
int back = -1;
int inQue(int elem)
{
    Que[++back] = elem;
    printf("Insterted - %d at pos %d\n",elem,back);
}
int DeQue()
{
    front++;
    printf("Dequed - %d and Front is - %d\n",Que[front],front);
    return Que[front];
}
int main()
{    
    inQue(3);
    inQue(5);
    inQue(7);
    DeQue();
    inQue(10);
    inQue(11);
    DeQue();
    printf("The Que is--------------- \n");
    for (int i = front+1 ; i <= back ; i++)
    {
        printf("%d\t",Que[i]);
    }
    return 0;
}