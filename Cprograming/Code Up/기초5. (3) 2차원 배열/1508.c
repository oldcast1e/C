#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d;
    int num[20];
    int dnum[100][100];

    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&num[i]);
    }
    int cnt = 1;
    for(int i=0;i<a;i++){
        dnum[i][0] = num[i];// printf("> dnum[%d][0] = %d\n",i,dnum[i][0]);
        for(int j=1;j<cnt;j++){
            dnum[i][j] = dnum[i][j-1] - dnum[i-1][j-1];
            // printf(">>dnum[%d][%d] (%d) = %d - %d\n",i,j,dnum[i][j]
            // ,dnum[i][j-1], dnum[i-1][j-1]);
        }
        cnt ++;
    }

    int rst_cnt = 1;
    for(int i=0;i<a;i++){
        for(int j=0;j<rst_cnt;j++){
            printf("%d ",dnum[i][j]);
        }printf("\n");
        rst_cnt++;
    }
    
} 
/*

*/