/*8. Develop a menu driven Program in C for the following operations on Doubly Linked List
(DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo:
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit*/
#include<stdio.h>
#include<stdlib.h>
struct DList
{
	int ssn;
	char name[20];
	char desg[20];
	char dept[20];
	int sal;
	char phno[11];
	struct DList *prev,*next;
};
typedef struct DList dnode;
dnode *start=NULL;
dnode *create()
{
	dnode *newnode;
	newnode=(dnode*)malloc(sizeof(dnode));
	if(newnode==NULL)
		printf("Memory Overflow\n");
	else
	{
		printf("\n Enter ssn, name, designation,department,salary, phone number");
		scanf("%d%s%s%s%d%s",&newnode->ssn,newnode->name,newnode->desg,newnode->dept,&newnode->sal,newnode->phno);
		newnode->prev=NULL;
		newnode->next=NULL;
	}
return newnode;
}
void insert_front()
{
	dnode *nn;
	nn=create();
	if(start==NULL)
		start=nn;
	else
	{
		nn->next=start;
		start->prev=nn;
		start=nn;
	}
}
void delete_front()
{
	dnode *temp=start;
	if(start==NULL)
		printf("\n List is empty");
	else if(start->next==NULL)//single node
	{
		start=NULL;
		free(temp);
	}
	else
	{
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
}
void insert_end()
{
	dnode *nn,*temp;
	nn=create();
	if(start==NULL)
		start=nn;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	nn->prev=temp;
	}
}
void delete_end()
{
	dnode *temp=start;
	if(start==NULL)
		printf("\n Empty list");
	else if(start->next == NULL)
	{
		start=NULL;
		free(temp);
	}
	else
	{	
		while(temp->next != NULL)
			temp=temp->next;
		(temp->prev)->next=NULL;
		free(temp);
	}
}
void traverse()
{
	int c=0;
	dnode *temp=start;
	if(start==NULL)
		printf("\n Empty list");
	else
	{
		printf("\n The details are");
		while(temp!=NULL)
		{
			printf("\n%d\t%s\t%s\t%s\t%d\t%s\t",temp->ssn,temp->name,temp->desg,temp->dept,temp->sal,temp->phno);
			c++;
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
		printf("\n Enter 1:create list\n2:insert_front\n3:insert_end\n4:delete_front\n5:delete_end\n 6:Display");
		scanf("%d",&m);
		switch(m)
		{
			case 1: printf("\n Enter n");
 					scanf("%d",&n);
 					for(i=0;i<n;i++)
 					insert_end();
					break;
			case 2: insert_front();break;
			case 3: insert_end();break;
			case 4: delete_front();break;
			case 5: delete_end();break;
			case 6: traverse();break;
			default:exit(0);break;
		}
	}
	return 0;
}