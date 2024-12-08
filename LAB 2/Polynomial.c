/*. Develop a Program in C for the following operationson Singly Circular nexted List (SCLL)
with header nodes:
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2 y2 z2 - 4yz5 + 3x3 yz+2xy5 z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) 
and store the result in POLYSUM(x,y,z).
Support the program with appropriate functions for each of the above operations.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
 int cf,px,py,pz,used;
 struct poly *next;
};
typedef struct poly node;
node* create()
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Enter the polynomial term(coeff, power of x, y, z):");
	scanf("%d%d%d%d",&newnode->cf,&newnode->px,&newnode->py,&newnode->pz);
	newnode->used=0;
	newnode->next=NULL;
	return newnode;
}
void insert_front(node* head)
{
	node* nn;
	nn=create();
	nn->next = head->next;
	head->next = nn;
}
void read_poly(node *head)
{
	int n,i;
	printf("Enter the no. of terms in polynomial:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	insert_front(head);
}
void display(node *head)
{
 	node *temp = head->next;
 	while(temp!= head)
 	{
		printf(" %+dx^%dy^%dz^%d",temp->cf,temp->px,temp->py,temp->pz);
		temp=temp->next;
 	}
}
void add_poly(node* h1, node* h2, node* h3)
{
	node *t1=h1->next, *t2,*nn;
	while(t1!=h1)
	{
		nn=(node*)malloc(sizeof(node));
		*nn=*t1;
		t2=h2->next;
		while(t2!=h2)
		{
			if(t2->used==0 && t1->px==t2->px && t1->py==t2->py && t1->pz==t2->pz)
			{
				nn->cf+=t2->cf;
				t2->used=1;
			}
			t2=t2->next;
		}
		nn->next=h3->next;
		h3->next=nn;
		t1=t1->next;
	}
	t2=h2->next;
	while(t2!=h2)
	{
		if(t2->used==0)
		{
			nn=(node*)malloc(sizeof(node));
			*nn=*t2;
			nn->next=h3->next;
			h3->next=nn;
		}
		t2=t2->next;
	}
}
void evaluate(node *h)
{
	int x,y,z,sum=0;
	node *temp=h->next;
	printf("Enter the values of x, y, z:");
	scanf("%d%d%d",&x,&y,&z);
	while(temp!=h)
	{
		sum+=temp->cf*pow(x,temp->px)*pow(y,temp->py); //  chnages are there 
		pow(z,temp->pz);
		temp=temp->next;
	}
	printf("Evaluated value is %d\n",sum);
}
int main()
{
	node *h1,*h2,*h3;
 	h1 = (node*) malloc(sizeof(node));
 	h1->next = h1;
 	h2 = (node*) malloc(sizeof(node));
 	h2->next = h2;
 	h3 = (node*) malloc(sizeof(node));
 	h3->next = h3;
 	printf("First polynomial\n");
 	read_poly(h1);
 	printf("Second polynomial\n");
 	read_poly(h2);
 	add_poly(h1,h2,h3);
 	printf("\nTHE FIRST POLY IS\n");
 	display(h1);
 	printf("\nTHE SEC POLY IS\n");
 	display(h2);
 	printf("\nADDition of TWO poly are\n");
 	display(h3);
 	evaluate(h3);
}