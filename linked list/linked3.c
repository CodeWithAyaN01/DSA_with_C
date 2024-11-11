#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head;
    struct node *list[5];
    head = malloc(sizeof(struct node));
    for (int i = 0 ; i<5 ; i++)
    {
        list[i] = malloc(sizeof(struct node)); //  created multiple node 
    }

    for (int i = 0 ; i<5 ; i++)
    {
        list[i]->data = i+1;
        list[i]->next = list[i+1]; 
    }
    for (int i = 0 ; i<5 ; i++)
    {
        printf("The data of node[%d] is = %d\n",i,list[i]->data);
    }
    printf("\nProgram runs fine: ");
}