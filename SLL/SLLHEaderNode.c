#include<stdio.h>
#include<stdlib.h>

struct cll
{
    int data;
    struct cll *next;
};
typedef struct cll Node;
Node *start = NULL;
Node *create()
{
    Node *nn;
    nn = (Node*)malloc(sizeof(Node));
    printf("Enter data to be stored in node\n"); 
    scanf("%d",&nn->data);
    nn->next = NULL;
    return(nn);
}

void insert_front()
{
    Node *nn;
    if (start == NULL)
        start = nn;
    nn->next = start->next;
    start->next = nn;
    start->data++;
}

void delete_front()
{
    Node *temp;
    if(start->next == start)
    {
        printf("Empty");
        return;
    }
    temp = start->next;
    start->data--;
    start->next = (start->next)->next;
}