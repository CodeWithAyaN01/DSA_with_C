/*3. Develop a menu driven Program in C for the following operations on STACK of Integers(Array Implementation of Stack with maximum size MAX):
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each 
of the above operations*/

#include<stdio.h>
#include<math.h>
#define max 5
int stack[max],top=-1;
void push(int m)
{
	if(top==max-1)
		printf("\nStack overflow");
	else
	{
		top++;
		stack[top]=m;
	}
}
int pop()
{ 
	if(top==-1)
	{
		printf("\nStack underflow");
		return -1;
	}
	else
		return stack[top--];
}
void display()
{
	int i;
	if(top==-1)
		printf("\nStack is empty");
	else
	{	
		printf("\nThe elements are\n");
		for(i=top;i>=0;i--)
			printf("%d\t",stack[i]);
	}
}
void palindrome()
{
	int n,num,rem,i;
	top=-1;
	printf("\nEnter number");
	scanf("%d",&n);
	num=n;
	while(num!=0)
	{
		rem=num%10;
		push(rem);
		num=num/10;
	}
	num=0;
	for(i=0;top!=-1;i++)
		num=pop()*(pow(10,i)+num);
	
	if(n==num)
		printf("\nIt is a palindrome");
	else
		printf("\nIt is not a palindrome");
}
int main()
{
	int c,m;
	while(1)
	{	printf("\nEnter your choice\n1-push\n2-pop\n3-display\n4-palindrome\t: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	printf("\nEnter an element\t");
				scanf("%d",&m);
				push(m);
				break;
			case 2:m=pop();
				if(m!=-1)
					 printf("\nThe popped element is %d",m);
				break;
			case 3:	display();
					break;
			case 4:	palindrome();
					break;
			default:return 0;
		}
	}
}