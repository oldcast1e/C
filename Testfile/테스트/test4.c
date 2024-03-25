#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //순환문이용
    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);

    /*이중동적*/
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }



} 
/*
*/