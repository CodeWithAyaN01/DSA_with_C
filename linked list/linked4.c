#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct node
{
    int data;
    struct node* next;
};
struct node* CreatNode(int data)
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}
void InsertAtBeg(struct node ** head,int data)
{
    struct node * NewNode = CreatNode(data);
    NewNode->data = data;
    NewNode->next = *head;
    *head = NewNode; // updating head to the next new node
}
void insertAtEnd(struct node ** head , int data) //  head stores the adders of the 
{
    struct node * NewNode = CreatNode(data);
    NewNode->data = data;
    NewNode->next = NULL;

    if (*head == NULL)
    {
        *head = NewNode; // list empty condition 
    }
    struct node * temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NewNode; // connecting to the last node !

}
int main()
{
    struct node * head = NULL;
    
}