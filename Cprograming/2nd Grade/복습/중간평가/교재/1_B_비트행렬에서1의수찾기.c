#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int findOnes(int **dnum, int n){
    int i = n-1, j = 0;
    int cnt = 0, sum = 0;
    while(i >= 0 && j<n){
        if(dnum[i][j] == 1){
            cnt ++;
            printf("[%d][%d]\n",i,j);
            j ++;
            // i--;
        }
        if(dnum[i][j] == 0){
            // printf("[cnt = %d][i = %d][j = %d]\nsum = %d\n",cnt,i,j,sum);
            sum += (i+1)* cnt;
            i --;
            // j --;
            cnt = 0;
        }
    }
    return sum + cnt;
}



int main(){
    int n; scanf("%d",&n);
    int **dn = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dn[i] = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) {scanf("%d",&dn[i][j]);} 

    int rst = findOnes(dn,n);
    printf("rst  = %d",rst);
    
}
/*

8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0

*/