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
// delete function 
node* Delete(node *root, int val)  
{  
 node *temp;  int min; 
    if (root == NULL)  
 {  
  printf("tree is empty\n"); 
    return NULL; 
 } 
 // val is in the left sub tree. 
 if (val  <  root->val)  
 {         
  root->left = Delete(root->left, val);  
  return(root); 
 }  
 // val is in the right sub tree. 
 if (val  >  root->val)  
 {     
  root->right = Delete(root->right, val); 
      return(root); 
 }  
               // val is present but no children 
 if (root->left == NULL && root->right == NULL)  
 {     
    printf("deleted val %d",root->val); 
    free(root);  
    root = NULL; 
    return(root); 
 } 
 
    // val is present but no right subtree  
if (root->right == NULL)
{   
    temp = root->left; 
    printf("deleted val %d",root->val); 
    free(root); 
    return(temp); 
} 
     // val is present but no left subtree   
     if (root->left == NULL)  
     {       
  temp = root->right; 
             printf("deleted info %d",root->val); 
             free(root); return(temp); 
     } 
    // If both left and right subtree are present, find the min element  
   // in right subtree and place it in root node and call delete function 
   //for right subtree. 
    min = FindMin(root->right);  
     root->val = min;  
     root->right = Delete(root->right, min); 
  return(root); 
 
}
//Case 2: Data is in the left subtree  
if (val < root->val)  
{  
    root->left = Delete(root->left, val);   
    return(root);  
} 
//Case 3: Data is in the right subtree  
if (val > root->val)  
{  
    root->right = Delete(root->right, val);   
    return(root);  
} 
//Case 4: Data is present but no children  
if (root->left == NULL && root->right == NULL)  
{  
    printf("deleted val %d",root->val);   
    free(root);  
    root = NULL;  
    return(root);
}  