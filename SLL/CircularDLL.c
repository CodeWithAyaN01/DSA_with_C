#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct dll {
    int data;
    struct dll *l, *r;
};

typedef struct dll node;

node *start = NULL;

// Function to create a new node
node *create() {
    node *nn;
    nn = (node*)malloc(sizeof(node));
    printf("Enter the Data: ");
    scanf("%d", &nn->data);
    nn->r = NULL;
    nn->l = NULL;
    return nn;
}

// Insert a node at the front of the Circular DLL
void insert_front() {
    node *nn = create();
    if (start == NULL) { // List is empty
        start = nn;
        nn->r = nn; // Circular link
        nn->l = nn;
    } else {
        node *last = start->l; // Find the last node
        nn->r = start;
        nn->l = last;
        start->l = nn;
        last->r = nn;
        start = nn; // Update start to the new node
    }
}

// Insert a node at the end of the Circular DLL
void insert_end() {
    node *nn = create();
    if (start == NULL) { // List is empty
        start = nn;
        nn->r = nn; // Circular link
        nn->l = nn;
    } else {
        node *last = start->l; // Find the last node
        last->r = nn;
        nn->l = last;
        nn->r = start;
        start->l = nn;
    }
}

// Delete a node from the front of the Circular DLL
void delete_front() {
    if (start == NULL) { // List is empty
        printf("Empty List.\n");
        return;
    }
    node *temp = start;
    if (start->r == start) { // Only one node
        start = NULL;
        free(temp);
    } else {
        node *last = start->l; // Find the last node
        start = start->r;
        start->l = last;
        last->r = start;
        free(temp);
    }
}

// Delete a node from the rear of the Circular DLL
void delete_rear() {
    if (start == NULL) { // List is empty
        printf("Empty List.\n");
        return;
    }
    node *last = start->l;
    if (start->r == start) { // Only one node
        start = NULL;
        free(last);
    } else {
        node *second_last = last->l; // Find the second last node
        second_last->r = start;
        start->l = second_last;
        free(last);
    }
}

// Display the contents of the Circular DLL
void display() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = start;
    printf("The contents of the list are: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->r;
    } while (temp != start);
    printf("(back to start)\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_end(); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
