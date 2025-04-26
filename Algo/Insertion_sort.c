#include <stdio.h>
#include <stdlib.h>
void insertionSort(int A[] , int n) {
    for (int i = 1 ; i<n ; i++) {
        int current = A[i];
        int prev = i-1;
        while (prev>=0 && A[prev] >= current) {
            A[prev+1] = A[prev];
            prev--;
        }
        A[prev+1] = current;
    }
}
int main() {
    int A[] = {1,4,6,3,4,6};
    int n = 6;
    insertionSort(A,n);
    for (int i= 0 ; i<n ; i++) {
        printf("%d ",A[i]);
    }


}

