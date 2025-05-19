#include<stdio.h>
int n,m,p[10],w[10];
int max(int a, int b)
{
    return(a>b?a:b);
}

void knapDP() {
    int v[10][10] , i ,j;

    for (int i = 0 ; i <= n; i++) {
        for (int j = 0 ; j<= m ; j++) {
            if (i ==0 || j==0) {
                v[i][j] = 0;
            }
            else if (j<w[i]) {
                v[i][j] = v[i-1][j];
            }
            else {
                v[i][j] = max(v[i][j],p[i] + v[i-1][j-w[i]]);
            }
        }
    }
    for (i = 0 ; i<=n;i++) {
        for (j = 0 ; j <=m ; j++) {
            printf("%d  ",v[i][j]);
        }
        printf("\n");
    }

    // for ite included are :

    printf("Items included are : ");

    while (n>0) {
        if (v[n][m] != v[n-1][m]) {
            printf("%d ",n);
            m = m- w[n];
        }
        n--;
    }
}

int main() {
    int i;
    printf("Enter the no. of items: ");
    scanf("%d",&n);
    printf("Enter the weights of n items: ");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the prices of n items: ");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter the capacity of Knapsack: ");
    scanf("%d",&m);
    knapDP();
}