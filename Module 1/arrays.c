// #include <stdio.h>
// int main() {
//     int arr[] = {10, 20, 30, 40, 50};  // Initial array
//     int N = 5;  // Initial size of array
//     int ITEM = 25;  // New element to insert
//     int K = 2;  // Position where the element will be inserted (0-based index)
    
//     for (int i = N ; i>K ; i--)
//     {
//         arr[i] = arr[i-1];
//     }
//     arr[K] = ITEM;

//     for (int i = 0 ; i< N+1 ; i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }


// deleting vlues

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = 7;
//     int k = 3;
//     int item = arr[k];

//     for (int i = k ; i < n-1 ; i++)
//     {
//         arr[i] = arr[i+1];
//     }
//     n--;
//     for (int i = 0 ; i < n ; i++)
//     {
//         printf("%d ",arr[i]);
//     }

//     return 0;
// }


// SOME OF TWO MATRIX::

#include<stdio.h>
int main()
{
    int a[20][20],b[20][20],c[20][20];
    int i,j,k;
    int n,m,p,q;
    printf("Enter n m p q respectevely: ");
    scanf("%d",&n);scanf("%d",&m);scanf("%d",&p);scanf("%d",&q);
    // row major order;
    for (i = 0 ; i < n ; i++) // 1st matrix;
        for(j = 0 ; j<m ; j++)
        {
            scanf("%d",&a[i][j]);
        }

    for (i = 0 ; i < p ; i++) // 2st matrix;
        for(j = 0 ; j<q ; j++)
        {
            scanf("%d",&b[i][j]);
        }

    for (i = 0 ; i < n ; i++) // suming
        for(j = 0 ; j<q ; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    for (i = 0 ; i < n ; i++) // printing 3X3
        for(j = 0 ; j<q ; j++)
        {
            printf("%d ",c[i][j]);
        }
    return 0;
}
