#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //순환문이용
    int n,cnt = 1; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        if(i%2 == 0){
            for(int j=0;j<n;j++){
                dnum[i][j] = cnt; cnt ++;
            }
        }
        else for(int j=n-1;j>=0;j--){
                dnum[i][j] = cnt; cnt ++;
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf(" %d",dnum[i][j]);
        printf("\n"); 
    }
   



} 
/*
*/