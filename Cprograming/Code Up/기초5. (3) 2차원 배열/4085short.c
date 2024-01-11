#include<stdio.h>
int main(){int n,m,x,y,cnt=0,max=-1,dnum[100][100];scanf("%d %d %d %d",&m,&n,&x,&y);for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&dnum[i][j]);
for(int i=n-1;i>=0;i--){for(int j=m-1;j>=0;j--){cnt = 0;for(int row=0;row<y;row++){if(i-row < 0) continue;cnt+=dnum[i-row][j];}dnum[i][j] = cnt;}}
for(int i=n-1;i>=0;i--){for(int j=m-1;j>=0;j--){cnt = 0;for(int cro=0;cro<x;cro++){if(i-cro < 0) continue;cnt+=dnum[i][j-cro];}dnum[i][j] = cnt;}}for(int i=0;i<n;i++){for(int j=0;j<m;j++){if(dnum[i][j]>max)max=dnum[i][j];}}printf("%d",max);} 
