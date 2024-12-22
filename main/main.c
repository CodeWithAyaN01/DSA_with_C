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
    return stack[top--];
}
int prec(char opr)
{
    if(opr=='^'||opr=='%') return(4);
	if(opr=='*'||opr=='/') return(3);
	if(opr=='+'||opr=='-') return(2);
	if(opr=='('||opr=='#') return(1); 
}
void main()
{
    char infix[100],postfix[100];
    int i,j = 0;

    printf("Enter infix Expresion: ");
    gets(infix);
    push('#');
    
    for (i = 0 ; infix[i] != '\0' ; i++)
    {
        if (infix[i] = '(')
        {
            push('(');
        }
        else if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] = ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while( prec(stack[top]) >= prec(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    
    while (stack[top] != '#')
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("\n INFIX EXPRESSION = %s",infix);
    printf("\n POSTFIX EXPRESSION = %s",postfix);
}