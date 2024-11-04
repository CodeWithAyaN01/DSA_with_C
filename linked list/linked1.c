#include<stdio.h>
struct node 
{
    int data; // the data of the link list 
    struct node *link; // the address to the new data
};
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = 55;
    head->link = NULL;
}
