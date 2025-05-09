/*10. Develop a menu driven Program in C for the following operations on Binary Search Tree (BST)
of Integers.
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit*/
#include<stdio.h>
#include<stdlib.h>
struct Tree 
{
	int data;
	struct Tree *left,*right;
};
typedef struct Tree tnode;
tnode *root=NULL;
tnode* getnode() 
{
	tnode *newnode;
	newnode=(tnode*)malloc(sizeof(tnode));
	printf("\n Enter the value");
	scanf("%d",&newnode->data);
	newnode->left=newnode->right=NULL;
	return(newnode);
}
void insert()
{
	tnode *nn,*temp=root,*prev;
	nn=getnode();
	if(root==NULL)
		root=nn;
	else 
	{
		while(temp!=NULL) 
		{
			prev=temp;
			if(nn->data < temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(nn->data < prev->data)
			prev->left=nn;
		else
			prev->right=nn;
	}	
}
void inorder(tnode *root) 
{
	if(root!=NULL) 
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(tnode *root) 
{
	if(root!=NULL) 
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(tnode *root) 
{
	if(root!=NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int search(int key) 
{
	tnode *temp=root;
	while(temp!=NULL)
	{
		if(key==temp->data)
			return 1;
		else if(key<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	return 0;
}
void display(tnode *root,int height) 
{
	int i;
	if(root!=NULL) 
	{
		display(root->right,height+1);
		for(i=0;i<height;i++)
			printf("\t");
		printf("%d\n",root->data);
		display(root->left,height+1);
	}
}
int main()
{
	int ch,key,n,i;
	while(1)
	{
		printf("\n Enter\n 1:insert\t 2:traverse\t 3:search\t 4:display\t 5:exit \t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter no of terms");
 			scanf("%d",&n);
 			for(i=0;i<n;i++)
 				insert();
			break;
			case 2: if(root==NULL)
						printf("\n Tree empty");
 					else
 					{
						printf("\nInorder traversal:\t");
						inorder(root);
						printf("\nPreorder traversal:\t");
						preorder(root);
						printf("\nPostorder traversal:\t");
						postorder(root);
					}
					break;
			case 3: printf("\n Enter the key");
					scanf("%d",&key);
					if(search(key))
						printf("Search is successful");
					else
						printf("Search is unsuccessful");
 					break;

			case 4: display(root,0);
					break;
			case 5: return 0;
		}
	}	
}