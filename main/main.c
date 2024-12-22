#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *start = NULL;

Node *creat()
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Overflow mwmory:");
        return NULL;
    }
    else
    {
        printf("Enter data");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        return newnode;
    }
}
void Insert_f()
{
    Node *NN;
    NN = creat();
    NN->next = start;
    start = NN;
}

void Delete_f()
{
    Node *temp;
    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}

void insert_End()
{
    Node *NN;
    Node *temp;
    NN = creat();
    if (start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NN;
    }
}

void Delete_end()
{
    Node *temp = start;
    Node *prev;
    if (start == NULL)
    {
        printf("Empty");
        return;
    }
    if (start->next == NULL)
    {
        start =NULL;
    }
    else
    {
        while (temp->next != NULL)
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
    int c = 0;
    Node *temp;
    if (start == NULL)
    {
        printf("Empty");

    }else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("Data is %d\n",temp->data);
            c++;
            temp = temp->next;
        }
        printf("number of node si %d",c);
    }

}
   
int main() {
    int n;
    while (1) {
        printf("\nEnter your choice:\n1: Insert Front\n2: Insert End\n3: Delete Front\n4: Delete End\n5: Display\n0: Exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                Insert_f();
                break;
            case 2:
                insert_End();
                break;
            case 3:
                Delete_f();
                break;
            case 4:
                Delete_end();
                break;
            case 5:
                display();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
