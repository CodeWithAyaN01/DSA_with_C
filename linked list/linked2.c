#include<stdio.h>
struct node 
{
    int data;
    struct node* next;
};
struct node* CreatNode(int data)
{
    struct node* node1 = malloc(sizeof(struct node));
    node1->data = 99;
    node1->next = NULL;
}
void appendNode(struct node** head,int data)
{
    struct node* newnode = CreatNode(data);
    if (*head == NULL)
    {
        *head = newnode;
    }else
    {
        struct node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}