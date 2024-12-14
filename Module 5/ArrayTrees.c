#include<stdio.h>
#include<stdlib.h>
#define max 10
void insert(int data,int a[])
{
    int i = 0;
    while (i<max && a[i]!=0)
    {
        if(data < a[i])
        {
            i = i*2 +1; // left
        }
        else
        {
            i = i*2+2; // right
        }
    }
    a[i] = data;
}

void inorder(int i,int a[])
{
    if(a[i])
    {
        inorder(i*2+1,a); // right
        printf("%d",a[i]);
        inorder(i*2+2,a); //left
    }
}

void preorder(int i,int a[])
{
    if(a[i])
    {
        printf("%d",a[i]);
        inorder(i*2+1,a); // right
        inorder(i*2+2,a); //left
    }
}
void postorder(int i,int a[])
{
    if(a[i])
    {
        inorder(i*2+1,a); // right
        inorder(i*2+2,a); //left
        printf("%d",a[i]);
    }
}
