#include<stdio.h>
#include<stdlib.h>
struct sll {
    int data;
    struct sll *next;
};
typedef struct sll node;

node *start = NULL;

node* Create(){
    node* nn;
    nn = (node*)malloc(sizeof(node)); // memory allotment
    printf("Enter the Data For new node: ");
    scanf("%d" , nn->data);
    nn ->next = NULL;
    return(nn);
}

void insertFront()
{
    node * nn;
    nn = Create();
    if (start == NULL)
    {
        start = nn;
    }
    else
    {
        nn->next = start;
        start = nn;
    }
}
void insertRear()
{
    node *temp;
    node *nn;
    if (start == NULL)
    {
        start = nn;
        return;
    }
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}
// void createNnodes()
// {
//     int i , n;
//     printf("Enter the number of Students");
//     scanf("%d",&n);
//     for (i = 0 ; i<=n ; i++){
//         insertFront();
//     }
// }

void deleteFront() // increment start
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty: ");
        return;
    }
    if (start->next == NULL)
    {
        printf("Deleted Student is : %d",start->data);
        free(temp);
    }
    start = start->next;
    printf("deleted student is %d",temp->data);
    free(temp);
}

void deleteRear()
{
    node *temp = start;
    node *prev;
    if (start == NULL)
    {
        printf("EmptyList: ");
        return;
    }
    if (start->next == NULL)
    {
        start = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted student is = %s",temp->data);
    prev->next = NULL;
}

void display()
{
    node *temp;
    if(start == NULL)
    {
        printf("the Lisv is empty");
    }
    printf("The contents of list are: ");
    for (temp = start ; temp->next!= NULL ;temp = temp->next )
    {
        printf("%d\t",temp->data);
    }
}
