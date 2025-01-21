#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};

typedef struct stack node;

node *top = NULL;

node *create()
{
    node *nn;
    nn = (node*)malloc(sizeof(node));
    printf("\nEnter the Value: ");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

void push() // insert Front
{
    node *nn;
    nn = create();
    if(top == NULL)
    {
        top = nn;
        return;
    }
    nn->next = top;
    top = nn;
}

void pop()
{
    node *temp;
    if (top == NULL)
    {
        printf("Empty Stack");
    }
    if(top->next == NULL)
    {
        top = NULL;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    node *temp;
    temp = top;
    if(top == NULL)
    {
        printf("Empty");
    }
    while (temp != NULL)
    {
        printf("%d---",temp->data);
        temp=temp->next;
    }
    // free(temp);
}
int main()
{
    push();
    push();
    push();
    push();
    push();
    pop();
    pop();
    display();
}