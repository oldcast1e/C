#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Alg prefixAverages1(X, n) {ver.1} input array X of n integers
output array A of prefix averages of X
1. for i ← 0 to n – 1 sum ← 0
for j ← 0 to i
sum ← sum + X[j]
A[i] ← sum/(i + 1) 2. return A
*/
int *prefixAverages1(int *X,int n){
    int sum;
    int *rst = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum  = 0;
        for(int j=0;j<i;j++) sum += X[j]; 
        rst[i] = sum;
    }
    return rst;
}

int *prefixAverages2(int *X,int n){
    int sum=0;
    int *rst = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum += X[i]; 
        rst[i] = sum;
    }
    return rst;
}
int main(){
    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);

    /*이중동적*/
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);

    
    

    
} 
/*

*/