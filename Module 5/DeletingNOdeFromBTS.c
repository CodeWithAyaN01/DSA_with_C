#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left, *right;
}node;

node *Delete(node *root , int data)
{
    node *temp;
    int min;
    if (root == NULL)
    {
       printf("Empty");
       return NULL; 
    }

    // left sub tree

    if (data < root->data)
    {
        root->left = Delete(root->left,data);
    }

    // right sub tree

    if (data > root->data)
    {
        root->right = Delete(root->right,data);
    }

    // data is present but no children 

    if (root->left == NULL && root->right ==NULL)
    {
        printf("Deleted data %d",root->data);
        free(root);
        root = NULL;
        return root;
    }

     // data is present but no right subtree

    if (root->right == NULL)
    {
        temp = root->left; // storing in left sub tree
        printf("deleted data %d",root->data); 
        free(root); 
        return(temp);
    }

     // data is present but no left subtree

    if (root->left == NULL)
    {
        temp = root->right; // storing in right sub tree
        printf("deleted data %d",root->data); 
        free(root); 
        return(temp);
    }
}