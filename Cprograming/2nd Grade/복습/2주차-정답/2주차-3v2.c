#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *prefixAverages1(int x[],int n){
    float sum = 0;// <==== 핵심
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=0;j<=i;j++) sum += x[j];
        rst[i] = (int)((sum / (i + 1))+0.5);
    }
    return rst;
    //A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
}

int *prefixAverages2(int x[],int n){
    float sum = 0;
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        sum += x[i];
        rst[i] = (int)((sum / (i + 1))+0.5);
    }
    return rst;
    //A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
}
int main(){

    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    int *rst1 = prefixAverages1(num,n);
    int *rst2 = prefixAverages2(num,n);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);printf("\n");
    for(int i=0;i<n;i++)printf("%d ",rst2[i]);
} 
/*
3
5 1 9

6 
1 3 2 10 6
*/