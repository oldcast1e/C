#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i=1,j=0; scanf("%d %d",&n,&m);
    int dnum[101][100];
    
    int cnt = 1;
    for(int j=1;j<n+m;j++){//대각선의 수
        int tmp_j = j;
        if(tmp_j > m){
            tmp_j = m;
            i++;
        }
        int tmp_i = i;
        while(tmp_j > 0){
            printf("[%d][%d] ",tmp_i,tmp_j);
            dnum[tmp_i][tmp_j] = cnt; cnt ++;
            tmp_j --;
            tmp_i ++;

            if(tmp_i > n)break;
        }printf("\n");

        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf(" %d",dnum[i][j]);
        printf("\n"); 
    }


    
} 
/*

*/