#include<stdio.h>
int count = 0;
int i = 0;
void length(char name[])
{
    while (name[i] != '\0')
    {
        count++;
        i++;
    }
    printf("length is %d",count);
}
int main()
{
    char n[20];
    printf("Enter length: ");gets(n);
    length(n);
    return 0;
}