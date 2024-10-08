#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int n;
    printf("Enter no of elem: ");scanf("%d",&n);
    int arr[10];
    ptr = (int* )malloc(n * sizeof(int));
    // ptr = &arr;
    printf("Enter vales: ");
    for (int i = 0 ; i<n ; i++)
    {
        scanf("%d",&ptr[i]); // on scanning we cannot do like this 
    }

    printf("printing: ");

    for (int i = 0 ; i<n ; i++)
    {
        printf("%d  ",ptr[i]);
        // ptr++;
    }
    return 0;
}