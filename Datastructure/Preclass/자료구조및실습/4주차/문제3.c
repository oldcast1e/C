#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d",&n);
    int cnt = 1;
    int **dnum = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        // printf("-");
        if(i%2 == 0) {
            for(int j=0;j<n;j++){
                dnum[i][j] = cnt; 
                cnt ++;
            }
        }
        else {
                for(int j=0;j<n;j++){
                    dnum[i][n-1-j] = cnt;
                    cnt ++;
                }   
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf(" %d",dnum[i][j]);
        printf("\n"); cnt++;
    }
    
} 
/*
4

*/