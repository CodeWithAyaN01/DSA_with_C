#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;
int partition(int a[], int low,int high)
{
    int pivot=a[low];
    int i = low+1;
    int j = high;
    int temp;
    while(1)
    {

        while(i<=high && a[i]<=pivot)
        {
            i++; count++;
        }

        while(j>0 && a[j]>pivot)
        {
            j--; count++;
        }

        count+=2;

        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] =temp;
        }
        else if(i>j)
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
        else
            return j;
    }
}

void quicksort(int a[],int low, int high)
{
    int s;
    if(low<high)
    {
        //partition to place pivot element in between left and right group
        s = partition(a,low,high);
        quicksort(a,low,s-1);
        quicksort(a,s+1,high);
    }
}
int main()
{
    int a[10000],n;
    printf("Enter the number of elements in an array:");
    scanf("%d",&n);
    printf("All the elements:");
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d ",a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nAfter sorting\n");
    for(int i=0;i<n;i++)
        printf("%d  ", a[i]);
    printf("\nNumber of basic operations = %d\n",count);
}