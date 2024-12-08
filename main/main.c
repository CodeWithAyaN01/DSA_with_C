#include<stdio.h>
int a[10][10] , visit[10] , n;
void DFS(int s)
{
    int i;
    visit[s] = 1;
    for(i = 1 ; i<=n ; i++)
    {
        if ((a[s][i] == 0) && (visit[i]== 0))
            DFS(i);
    }
} 
int main()
{
    int s,j,i;

    printf("Enter the number of  Vertices");
    scanf("%d",&n);

    printf("Enter thr matrix\n");
    for (i = 1 ;i<=n;i++)
    {
        for (j = 1 ; j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the source nodee");
    scanf("%d",&s);
    DFS(s);

    printf("The Node reachable form  %d are\n",s);
    for (i = 1 ; i<=n ; i++)
    {
        if (visit[i] == 1 && i!=s)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}