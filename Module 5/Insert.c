#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node using typedef
typedef struct TreeNode {
    int data;  // Node data
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    // Traverse the tree and insert the value in the correct position
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal to display the BST
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function
int main() {
    TreeNode* root = NULL;

    // Insert elements into the BST
    int values[] = {40, 20, 10, 50, 65, 45, 30};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert each value into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Display the BST using in-order traversal
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
