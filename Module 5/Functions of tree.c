#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// TO TAKE OUT HEIGHT OF THE TREE
typedef struct TreeNode node; 
int height(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return -1;  // Return -1 for null node (height of an empty tree is -1)
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Return the larger height of left or right subtree plus 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
void print( node *root)  
{  
if (root != NULL)  
{  
    print( root->left);  
    if(root->left == NULL && root->right == NULL)  
        printf("%d",root->val);  
    printf( root->right);  
}  
}