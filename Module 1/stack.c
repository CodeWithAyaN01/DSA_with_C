#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 10
int stack[max];
int top = -1;

void push(int p)
{
    if (top == max-1) // top is index of array
    {
        printf("stack is full: ");
    }
    else
    {
        stack[++top] = p;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("stack Underflow: ");
        return -1;
    }else
    {
        return stack[top--]; //returns top elem and returns the deleted elem;
    }
}

void display()
{
    int i ;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("the elem are : ");
        for(i = top ; i>=0 ; i--)
        {
            printf("%d  ",stack[i]);
        }
    }
}
// usnig stack
void palendrome()
{
    int i,num,rem;
    printf("Enter n; ");
    int n;scanf("%d",&n);
    top = -1;
    num = n;
    while (num != 0)
    {
        rem = num %10;
        push(rem);
        num = num /10;
    }
    num = 0;
    for (i = 0 ; top!=-1;i++)
        num = pop()*(int)pow(10,i)+num; // reversing the numebr 

    if (num  == n)  
        printf("palendrome: ");
    else
        printf("not palendrome");
}
int main()
{
    int c,m;
    while (1)
    {
        printf("1.push , 2.Pop , 3.display , 4.palendrome");
        scanf("%d",&c);
        switch (c)
        {
            case 1 : 
                    printf("Enter elem: ");
                    scanf("%d",&m);
                    push(m);
                    break;

            case 2 :  
                        m = pop();
                        if (m!=-1)
                        {
                            printf("the popped elem is %d",m);
                        }
                        break;
            case 3: display();break;
            case 4: palendrome();break;
        }
    }
    
}