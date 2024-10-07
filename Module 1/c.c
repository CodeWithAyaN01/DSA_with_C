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