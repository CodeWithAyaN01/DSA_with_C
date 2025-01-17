//4.Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char opr)
{	
	stack[++top] = opr;
}	
char pop()
{	
	return(stack[top--]);
}
int preced(char opr)
{	
	if(opr=='^'||opr=='%') return(4);
	if(opr=='*'||opr=='/') return(3);
	if(opr=='+'||opr=='-') return(2);
	if(opr=='('||opr=='#') return(1);
}
void main()
{	
	char infix[20],postfix[20];
	int i,j=0;
	printf("\nEnter valid INFIX expression\n");
	scanf("%s",infix);
	push('#');

	for(i=0; infix[i]!='\0'; i++)
	{	
		if(infix[i]=='(')
		    push('(');

		else if (isalnum(infix[i]))
			postfix[j++] = infix[i];
    
		else if (infix[i]==')')
		{   
			 while(stack[top] != '(')
			    postfix[j++] = pop();
			pop(); // for ) 
		}
        else
		{        
			while( preced(stack[top]) >= preced(infix[i]) )
			       postfix[j++] = pop();
			push(infix[i]);
		}
    }
	while(stack[top] != '#')
		postfix[j++] = pop();
	postfix[j]='\0';
	printf("\n INFIX EXPRESSION = %s",infix);
	printf("\n POSTFIX EXPRESSION = %s",postfix);
	getch();
}