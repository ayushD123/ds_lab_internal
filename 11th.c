#include <stdlib.h>
#include <stdio.h>

//int G[20][20];

void DFS(int start,int n,int G[][n],int *cnt)
{
 static int visited[20]={0};
 int j;
 
 if(visited[start]==0)
 {
 printf("%d",start);

 visited[start]=1;
 
 for(j=1;j<=n;j++)
 {
 if(G[start-1][j-1]==1 && visited[j]==0){
  printf("->");
  (*cnt)++;
 DFS(j,n,G,cnt);
 }
  
 }
 }
}
int main()
{
    int n,v;
    int cnt=0;
    
    printf("enter number of vertices-");
    scanf("%d",&n);
    printf("enter data adj matrix-");
   int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter starting vertex-");
    scanf("%d",&v);

 DFS(v,n,a,&cnt);
 printf("%d",cnt);
 if(cnt==(n-1)){
     printf("Connected graph");
 }else{
     printf("not Connected graph");
 }
 
 return 0;
}