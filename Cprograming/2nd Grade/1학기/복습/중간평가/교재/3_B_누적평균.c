#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* PA1(int X[],int n){
    int *R  = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        float sum = 0;
        for(int j=0;j<=i;j++) {
            sum += X[j];
            // printf("%d ",X[j]);
        }
        // printf("\n");
        R[i] = (int)(sum / (i+1) + 0.5);
    }
    return R;
}

int* PA2(int X[],int n){
    int *R  = (int*)malloc(sizeof(int)*n);
    float sum = 0;
    for(int i=0;i<n;i++){
        sum += X[i];
        R[i] = (int)(sum / (i+1) + 0.5);
    }
    return R;
}

int main(){
    int n = 3;
    int num[3] = {5,1,9};

    int *rst1 = PA1(num,3);
    int *rst2 = PA2(num,3);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);printf("\n");
    for(int i=0;i<n;i++)printf("%d ",rst2[i]);
}
/*
3
5 1 9

6
1 3 2 10 6 8
*/