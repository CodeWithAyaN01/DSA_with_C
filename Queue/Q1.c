#include<stdio.h>
#define size 10
int Que[size];
int front = -1;
int back = -1;
int inQue(int elem)
{
    Que[++back] = elem;
}
void DeQue()
{
    // int temp;
    // for(int i = 0 ; i < point ; i++)
    // {
    //     Que[i] = Que[i+1];
    // }
    // point--;
    front++;
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
    for (int i = front+1 ; i <= back ; i++)
    {
        printf("%d\t",Que[i]);
    }
    return 0;
}