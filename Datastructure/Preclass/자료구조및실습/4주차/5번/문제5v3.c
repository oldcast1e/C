#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,dnum[100][100]={0};
    scanf("%d %d",&n,&m);
    
    int cross = 1,cnt=1,i=0,j=0;
    int tmp_j = j,tmp_i=0;

    for(int r=0;r<n+m;r++){
        tmp_j = j,tmp_i=0;
        if(j > m){
            printf("><");
            j = m;
            i++;
        }
        for(int k=tmp_j;k>=0;k--){
            printf("[%d][%d] ",tmp_i,k);
            dnum[tmp_i][k]  = cnt; cnt++;
            tmp_j --;
            tmp_i ++;
        }printf("\n");
        j ++;
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",dnum[i][j]);
        printf("\n"); 
    }



    
} 
/*
1  2  4  7 
3  5  8    12 
6  9    13 18 
10   14 19 25 

1  2  4  7 
3  5  8    12 
6  9    13 27 
10    14 28 0 
*/