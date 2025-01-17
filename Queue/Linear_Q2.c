#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //  for boolean function
#define size 10
int queue[size];
int front = 0 , rear = -1;
 // full functin of Linear Quese
bool isFull()
{
    if (rear == size-1)
    {
        return true;
    }else
    {
        return false;
    }
}
bool isEmpty()
{
    if (front > rear)
    {
        return true;
    } else{
        return false;
    }
}
void insert(int data)
{
    if (front > rear)
    {
        front = 0;
        rear = -1;
    }
    if (rear == size-1)
    {
        printf("Queue is full");
        return;
    }
    queue[++rear] = data;
}

int delete()
{
    if (front > rear)
    {
        printf("Under flow conditionas");
    }
    printf("Item deleted is %d ",queue[front]);
    return queue[front++];
}
void display() 
{   
    int i; 
    if (front > rear) 
    {  
        printf("q is empty\n"); 
        front = 0; rear = -1; 
        return; 
    } 
    printf(" the contents of queue are"); 
    for ( i=front; i<= rear; i++) 
    printf("%d ",queue[i]); 
}
