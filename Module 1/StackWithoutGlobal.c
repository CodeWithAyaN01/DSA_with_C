#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Define the stack structure
struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        printf("Popped %d from the stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to display the stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;  // Declare a stack variable
    int choice, value;

    // Initialize the stack
    initStack(&stack);

    // Stack menu
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                // Pop operation
                pop(&stack);
                break;
            case 3:
                // Display stack
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
