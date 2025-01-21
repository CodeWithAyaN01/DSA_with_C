#include <stdio.h>
#include <stdlib.h>

struct Q {
    int data;
    struct Q *next;
};
typedef struct Q Node;

Node *start = NULL;

Node *create() {
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node)); // Memory allocation
    if (newNode == NULL) {
        printf("Memory overflow\n");
        return NULL;
    }
    printf("\nEnter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void insert() {
    Node *newNode = create();
    if (newNode == NULL) {
        return; // If memory allocation failed
    }
    if (start == NULL) {
        start = newNode;
    } else {
        Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nElement inserted successfully.\n");
}

void delete () {
    if (start == NULL) {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }
    Node *temp = start;
    start = start->next;
    free(temp);
    printf("\nElement deleted successfully.\n");
}

void display() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nList elements: ");
    Node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
