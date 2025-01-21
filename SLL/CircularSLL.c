#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct sll {
    int data;
    struct sll *next;
};
typedef struct sll node;

node *start = NULL;

// Function to create a new node
node* Create() {
    node* nn;
    nn = (node*)malloc(sizeof(node)); // Memory allocation
    printf("Enter the Data For new node: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
    return nn;
}

// Insert a node at the front of the Circular SLL
void insertFront() {
    node* nn = Create();
    if (start == NULL) { // List is empty
        start = nn;
        nn->next = start; // Circular link
    } else {
        node* temp = start;
        while (temp->next != start) { // Traverse to the last node
            temp = temp->next;
        }
        nn->next = start;
        temp->next = nn;
        start = nn; // Update start to the new node
    }
}

// Insert a node at the rear of the Circular SLL
void insertRear() {
    node* nn = Create();
    if (start == NULL) { // List is empty
        start = nn;
        nn->next = start; // Circular link
    } else {
        node* temp = start;
        while (temp->next != start) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = start; // Circular link
    }
}

// Create multiple nodes in the Circular SLL
void createNnodes() {
    int i, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        insertRear(); // Insert at the rear for simplicity
    }
}

// Delete a node from the front of the Circular SLL
void deleteFront() {
    if (start == NULL) { // List is empty
        printf("Empty list.\n");
        return;
    }
    node* temp = start;
    if (start->next == start) { // Only one node
        printf("Deleted node is: %d\n", start->data);
        free(start);
        start = NULL;
    } else {
        node* last = start;
        while (last->next != start) { // Traverse to the last node
            last = last->next;
        }
        printf("Deleted node is: %d\n", temp->data);
        start = start->next;
        last->next = start; // Update circular link
        free(temp);
    }
}

// Delete a node from the rear of the Circular SLL
void deleteRear() {
    if (start == NULL) { // List is empty
        printf("Empty list.\n");
        return;
    }
    if (start->next == start) { // Only one node
        printf("Deleted node is: %d\n", start->data);
        free(start);
        start = NULL;
    } else {
        node* temp = start;
        node* prev = NULL;
        while (temp->next != start) { // Traverse to the last node
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted node is: %d\n", temp->data);
        prev->next = start; // Update circular link
        free(temp);
    }
}

// Display the contents of the Circular SLL
void display() {
    if (start == NULL) { // List is empty
        printf("The list is empty.\n");
        return;
    }
    node* temp = start;
    printf("The contents of the list are: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start); // Stop when back to start
    printf("(back to start)\n");
}

// Display the contents of the Circular SLL and count the number of nodes
// void display_and_count() {
//     if (start == NULL) { // List is empty
//         printf("The list is empty.\n");
//         return;
//     }

//     node* temp = start;
//     int count = 0; // Initialize the node counter

//     printf("The contents of the list are: ");
//     while (1) {
//         printf("%d -> ", temp->data);
//         count++;
//         temp = temp->next;
//         if (temp == start) { // Stop when back to the start
//             break;
//         }
//     }

//     printf("(back to start)\n");
//     printf("Total number of nodes: %d\n", count);
// }

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Create Multiple Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: createNnodes(); break;
            case 7: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
