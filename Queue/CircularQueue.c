#include<stdio.h>
#include<stdlib.h>
#define max 5

int q[max];
int f = 0;
int r = -1;
count = 0;

void insert() {
    int item;
    if (count == max) {
        printf("Overflow Queue: ");
    }
    printf("Enter the element: ");
    scanf("%d",&item);
    r = (r+1) %max;
    q[r] = item;
    count++; //Count incremented;
}

void delete()
{
    if(count == 0) {
        printf("Empty Q");
    }
    printf("Element deleted is : %d",q[f]);
    f = (f+1)%max;
    count--;
}
void display()
{
    int i , c;
    i = f;
    if (count == 0)
    {
        printf("Empty Q");return;
    }
    else
    {
        for (c = 1 ; c<=count ; c++)
        {
            printf("%d\t",q[i]);
            i = (i+1) %max;
        }
    }
}