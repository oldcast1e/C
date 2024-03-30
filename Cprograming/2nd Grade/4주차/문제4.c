#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,cnt = 1; 
    
    scanf("%d %d",&n,&m);
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*m);
    //n * m의 배열 생성

    int right = m - 1,left = 0,top = 0,under = n-1;
    while(cnt <= n*m){
        for(int i=left;i<=right && cnt <= n*m;i++){
            dnum[top][i] = cnt; cnt++;
            // printf(" %d(1)\n",dnum[top][i]);
        }top ++; //  -> 방향
        for(int i=top;i<=under && cnt <= n*m;i++){
            dnum[i][right] = cnt; cnt++;
            // printf(" %d(2)\n",dnum[i][right]);
        }right --;// | 아래 방향
        for(int i=right;i>=left &&cnt <= n*m;i--){
            dnum[under][i] = cnt; cnt++;
            // printf(" %d(3)\n",dnum[under][i]);
        }under --;// <- 왼쪽 방행
        for(int i=under;i>=top &&cnt <= n*m;i--){
            dnum[i][left] = cnt; cnt++;
            // printf(" %d(4)\n",dnum[i][left]);
        }left++;// | 위쪽 방행
        // printf("cnt = %d\n",cnt);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf(" %d",dnum[i][j]);
        printf("\n"); 
    }


} 
/*
 1 2 3 4 5
 14 15 16 17 6
 13 20 19 18 7
 12 11 10 9 8

 1 2 3 4 5
 14 15 16 17 6
 13 20 19 18 7
 12 11 10 9 8
*/