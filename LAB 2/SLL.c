/*Develop a menu driven Program in C for the following operations on Singly
Linked List (SLL) of Student Data with the fields: USN, Name, Programme,
Sem, PhNo 
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of Nodes in it 
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit*/
#include<stdio.h>
#include<stdlib.h>
struct SLL
{
	char usn[11];
	char name[30];
	char branch[4];
	int sem;
	char phno[11];
	struct SLL *next; // pointer
};
typedef struct SLL Node;
Node *start=NULL;

// creating function
Node *create()
{
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node)); // memory allocation
	if(newNode==NULL)
		printf("Memory overflow");
	else
	{
		printf("\n Enter USN, name, branch, sem, phone number");
		scanf("%s%s%s%d%s",newNode->usn,newNode->name,newNode->branch,&newNode->sem,newNode->phno);
		newNode->next=NULL;
		return newNode;
	}
}
void insert_front()
{
	Node *newnode;
	newnode=create();
	newnode->next=start; // the node pointes to the start of the LL
	start=newnode; // updating the list to the start ;
}
void delete_front()
{
	Node *temp;
	if(start==NULL)
		printf("\n List is empty");
	else 
	{
		temp=start;
		start=start->next;
		free(temp);
	}
}
void insert_end() 
{
	Node *NewNode,*temp;
	NewNode=create();
	if(start==NULL)
		start=NewNode;
	else 
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=NewNode;
	}
}
void delete_end() 
{
	Node *temp=start,*prev;
	if(start==NULL) 
	{
		printf("\n Empty list");
		return;
	}
	if(start->next==NULL)
		start=NULL;

	else 
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
	}
	free(temp);
}
void display()
{
	int c = 0; //  to calculate number of nodes !
	Node *temp;
	if(start==NULL)
		printf("\n Empty list");
	else
	{
		temp=start;
		printf("\n The details are");
		while(temp!=NULL)
		{
			printf("\n%s\t%s\t%s\t%d\t%s\t",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
			c++; // increasing the number of nodes
			temp=temp->next;
		}
		printf("\n Number of nodes is %d",c);
	}
}
int main()
{
	int n,m,i;
	while(1)
	{
		printf("\n Enter your choice \n1:insert_front\n 2:insert_end\n 3:delete_front\n 4:delete_end\n5:display\n\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1: printf("\n Enter n");
 					scanf("%d",&n);
 					for(i=0;i<n;i++)
 						insert_front();//Inserting multiple nodes at once
					break;
			case 2: insert_end();break;
			case 3: delete_front();break;
			case 4: delete_end();break;
			case 5: display();break;
			default: return 0;
		}
	}
}