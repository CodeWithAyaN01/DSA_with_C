#include<stdio.h>
#include<stdlib.h>
struct DLL 
{
    int data;
    struct DLL *next,*prev;
};
typedef struct DLL Node;
Node *start = NULL;
Node *CreateNode()
{
    Node *NewNode;
    NewNode = malloc(sizeof(Node *));
    if (NewNode == NULL)
        printf("Memory Overflow");
    printf("GIve gata");
    scanf("%d",NewNode->data);
    NewNode->next=NULL;
    NewNode->prev=NULL;
    return NewNode;
}

void insertfront()
{
    Node *nn;
    nn = CreateNode();
    if(start==NULL)
    {
        start = nn;
    }
    else
    {
        nn->next = start;
        start->prev = nn;
        start = nn;
    }
}

void deleteFront()
{
    Node *temp = start;
    if (start == NULL)
    {
        printf("Empty");
    }
    else if(start->next == NULL)
    {
        start = NULL;
        free(temp);
    }
    else
    {
        start = start->next;
        start->prev = NULL;
        free(temp);
        
    }
}

void insertEnd()
{
    Node *nn;
    Node *temp = start;
    if(start == NULL)
    {
        start = nn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
}

void deleteEnd()
{
    Node *temp = start;
    if (start == NULL)
        printf("Empty");
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        (temp->prev)->next = NULL;
        free(temp);
    }
}

void Traverse()
{
    int c = 0;
    Node *temp = start;\
    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
        printf("The details Are");
        while (temp != NULL)
        {
            printf("print details: ");
            temp = temp->next;
            c++;
        }
        printf("\n Number of nodes is %d",c);
    }
}