// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int *ptr;
//     int arr[10];
//     int size = 6;
//     ptr = &arr; // assigning values to ptr
//     ptr = (int*)malloc(size * sizeof(int));
//     printf("Enter arr values: ");
//     for (int i = 0 ; i<size ; i++)
//     {
//         scanf("%d",&ptr[i]);
//     }
//     printf("printing values \n");
//     for (int i = 0 ; i<size ; i++)
//     {
//         printf("%d \t",*ptr);
//         ptr++;
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char *text;
//     char name[20];
//     int length;
//     printf("enter length of text: ");scanf("%d",&length);
//     text = (char*)calloc(length+1,sizeof(char));
//     text = &name;
//     printf("Enter name: ");
//     gets(name);
//     for (int i = 0 ; i<length ; i++)
//     {
//         printf("%c",*text);
//         text++;
//     }    
//     return 0;
// }

// INSERTING ELEMENT 

// #include<stdio.h>
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8};
//     int length = 8;
//     int item = 111;
//     int pos = 5;

//     for (int i = length ; i<pos ; i--)
//     {
//         arr[i+1] = arr[i];
//     }
//     arr[pos] = item;
//     // pritnng
//     length++;
//     for (int i = 0 ; i<length ; i++)
//     {
//         printf("%d\t",arr[i]);
//     }
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
int fibonachi(int num)
{
    if (num==0)
    {
        return 1;

    }else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibonachi(num-1) + fibonachi(num-2);
    }
}
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
       return  n * factorial(n-1);
    }
}
int main()
{
    int a = 5;
    factorial(5);
    printf("factorila of 5 is\n %d",factorial(5));
    printf("fibo of 5 is\n %d",fibonachi(5));
}