#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int *arr1,*arr2,*rst,n;
    scanf("%d",&n);
    arr1 = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&arr1[i]);
    arr2 = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&arr2[i]);
    
    rst = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        rst[i] = arr1[i] + arr2[n-1-i];
    }
    for(int i=0;i<n;i++)printf(" %d",rst[i]);

    
} 
/*
3
1 2 3
5 10 15

*/