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
    scanf("%d" , &nn->data);
    nn->next = NULL;
    return nn;
}

void insertFront()
{
    node *nn;
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
    nn = Create();
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
void createNnodes()
{
    int i , n;
    printf("Enter the number of Students: ");
    scanf("%d", &n);
    for (i = 0 ; i < n ; i++){
        insertFront();
    }
}

void deleteFront() // increment start
{
    node *temp = start;
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if (start->next == NULL)
    {
        printf("Deleted Student is: %d\n", start->data);
        free(temp);
        start = NULL;
        return;
    }
    start = start->next;
    printf("Deleted Student is: %d\n", temp->data);
    free(temp);
}

void deleteRear()
{
    node *temp = start;
    node *prev = NULL;
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if (start->next == NULL)
    {
        printf("Deleted Student is: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted Student is: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void display()
{
    node *temp;
    if (start == NULL)
    {
        printf("The List is empty\n");
        return;
    }
    printf("The contents of the list are: ");
    for (temp = start; temp!= NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
}

int main()
{
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Create N Nodes\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertRear();
                break;
            case 3:
                createNnodes();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteRear();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
