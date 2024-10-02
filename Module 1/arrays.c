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
