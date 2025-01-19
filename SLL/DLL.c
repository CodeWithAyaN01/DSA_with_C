#include<stdio.h>
#include<stdlib.h>

struct dll {
    int data;
    struct dll *l , *r;
};

typedef struct dll node;

node *start;

start = NULL; 

node *create()
{
    node *nn;
    nn = (node*)malloc(sizeof(node));
    printf("Enter the Datas: ");
    scanf("%d",&nn->data);
    nn->r = NULL;
    nn->l = NULL;
    return nn;
}

void insert_front()
{
    node *nn;
    nn = create();
    if(start == NULL)
        start = nn;
    else
    {
        nn->r = start;
        start->l = nn;
        start = nn;
    }
}

void delete_front()
{
    if (start == NULL)
    {
        printf("Empty Lsit");
        return;
    }
    if (start ->r == NULL)
    {
        start = NULL;
        return;
    }
    start = start->r; // incrementing Start;
    start->l = NULL;
}

void Delete_rear()
{
    node *temp = start;
    if(start == NULL)
        printf("Empty");
    if (start->r == NULL)
        start = NULL ;

    while (temp->r != NULL)
    {
        temp = temp->r;
    }
    (temp->l)->r = NULL;
}

void InsertEnd()
{
    node *nn, *temp;
    if(start == NULL)
        start = nn;
    temp = start;
    while(temp->r != NULL)
    {
        temp = temp->r;
    }
    temp->r = nn;
    nn->l = temp;
}