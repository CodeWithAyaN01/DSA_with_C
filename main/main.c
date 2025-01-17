#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[100];
int top = -1;

void push(char elem)
{
    stack[++top] = elem;
}

int pop()
{
    return stack[top--];
}

int prec(char elem)
{
    if ((elem == '^') || (elem == '%')) return(4);
    if ((elem == '*') || (elem == '/')) return(3);
    if ((elem == '+') || (elem == '-')) return(2);
    if ((elem == '(') || (elem == '#')) return(1);
}
int main()
{
    char infix[20],postfix[20];
    int i,j=0;
    printf("Type infix equation: ");
    scanf("%s",infix);
    push('#');

    for(i = 0; infix[i] != '\0' ; i++)
    {
        if (infix[i] == '(')
            push('(');
        else if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                postfix[j++] == pop();
            pop();
        }
        else
        {
            while (prec(stack[top]) >= prec(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

    }
    while (stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("\n INFIX EXPRESSION = %s",infix);
	printf("\n POSTFIX EXPRESSION = %s",postfix);
}