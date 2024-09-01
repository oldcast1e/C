#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    int n; scanf("%d",&n);
    
    /*일중동적*/
    // int *num = (int *)malloc(sizeof(int)*n);
    /*이중동적*/
    // int **dnum = (int **)malloc(sizeof(int*)*n);
    // for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);


} 