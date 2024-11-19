#include<stdio.h>
#include<stdlib.h>
struct Node{ // liked list Structure Defination. 
    int data;
    struct Node* next;
};

struct Node* Create_Node(int value) // return type is struct Node*
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL; // Nest node value is NULL
    return new_node;
}

struct Node* Add_Node(struct Node** head,int data)
{
    struct Node* new_node = Create_Node(data);
    if (head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ;temp->next = new_node;
}