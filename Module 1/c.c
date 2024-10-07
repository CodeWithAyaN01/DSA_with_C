#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int arr[10];
    int size = 6;
    ptr = &arr; // assigning values to ptr
    ptr = (int*)malloc(size * sizeof(int));
    printf("Enter arr values: ");
    for (int i = 0 ; i<size ; i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("printing values \n");
    for (int i = 0 ; i<size ; i++)
    {
        printf("%d \t",*ptr);
        ptr++;
    }
    return 0;
}