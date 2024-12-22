#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int data;
    Node *next;
}Node;

Node *start = NULL;

Node *creat()
{
    Node *nn;
    nn = malloc(sizeof(Node*));
    if (nn = NULL)
    {
        printf("Memory full");
    }else
    {
        printf("Enter the data: ");scanf("%d",nn->data);
        nn->next = NULL;
        return nn;
    }
}
void insertF()
{
    Node *nn;
    nn->next = start;
    start = nn;
}
void delFront()
{
    Node *temp;
    if (start == NULL)
    {
        printf("Empty only: ");
    }
    else
    {
        temp = start; // not imp
        start = start->next;
        free(temp);
    }    
}
void insertEnd()
{
    Node *temp = start;
    Node *nn = creat();
    if (start == NULL)
    {
        start = nn;
    }else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}
void deleteend()
{
    Node *temp;
    temp = start;
    Node *prev;
    if (start == NULL)
    {
        printf("Empty: ");
    }
    if(start->next = NULL)
    {
        start = NULL;
    }
    else
    {
        while(temp->next !=NULL)
        {
           prev = temp;
           temp = temp->next;
        }
        prev->next = NULL;
    }
    free(temp);
}

void display()
{
    int count = 0;
    Node *temp;
    if (start == NULL)
    {
        printf("Empty:");
    }
    else
    {
        temp = start;
        printf("the details are: ");
        while (temp)
    }
}