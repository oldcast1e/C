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

평균 계산 시 소수점 이하를 반올림하여 정수로 구한다. 
정확한 반올림을 위해, %.f를 쓰지 말고 int 성질을 이용해서 반올림하라.
*/
int *prefixAverages1(int *X,int n){
    float sum = 0;
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=0;j<=i;j++) sum += X[j];
        //for j ← 0 to i
        rst[i] = (int)((sum / (i + 1))+0.5);
    }
    return rst;
    
}
int *prefixAverages2(int *X,int n){
    float sum = 0;
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum += X[i];
        rst[i] = (int)((sum / (i + 1))+0.5);
    }
    return rst;
}
int main(){
    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    int *rst1 = (int *)malloc(sizeof(int)*n);
    int *rst2 = (int *)malloc(sizeof(int)*n);
    
    rst1 = prefixAverages1 (num,n);
    rst2 = prefixAverages1 (num,n);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);printf("\n");
    for(int i=0;i<n;i++)printf("%d ",rst2[i]);
} 
/*
3
5 1 9

6
1 3 2 10 6 8
*/