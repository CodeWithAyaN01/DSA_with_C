/*11. Develop a Program in C for the following operations on Graph(G) of Cities:
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS
method*/
#include<stdio.h>
int a[10][10],visit[10],n;
void DFS(int s) 
{
    int i;
    visit[s]=1;
    for(i=1;i<=n;i++) 
    {
        if((a[s][i]==1)&&(visit[i]==0))
        DFS(i);
    }
}
int main() 
{
    int i,s,j;
    printf("No of vertices\n");
    scanf("%d",&n);
    
    printf("\n Enter adjacency matrix");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    printf("\n Enter the source node");
    scanf("%d",&s);
    DFS(s); // calling

    printf("\n Nodes reachable from %d are \n",s);
    for(i=1;i<=n;i++)
        if(visit[i]==1 && i!=s)
            printf("%d\t",i);
    return 0;
}
