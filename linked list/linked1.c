// #include<stdio.h>
// struct node 
// {
//     int data; // the data of the link list 
//     struct node *link; // the address to the new data
// };
// int main()
// {
//     struct node *head = NULL;
//     head = (struct node *)malloc(sizeof(struct node));

//     head->data = 55;
//     head->link = NULL;
// }
#include<stdlib.h>
#include<stdio.h>
struct node 
{
    int data;
    struct node *link;
};
int main()
{
    struct node *Nodes[5];
    // memory Allocate in heap 
    //  this step creates 3 Nodes 
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second= (struct node*)malloc(sizeof(struct node));
    struct node *third= (struct node*)malloc(sizeof(struct node));

    head->data = 20;
    head->link = second;
    second->data = 30;
    second->link = third;
    third->data = 40;
    third->link = NULL;
    printf("Program is running fine: ");
}



