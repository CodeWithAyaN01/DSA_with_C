#include<stdio.h>
// basics
int main()
{
    int *p;
    int a = 6;
    p = &a;
    printf("%d\n",*p);
    printf("%d",a);
    return 0;
}