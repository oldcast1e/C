#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int currentMax(int A[], int n){
    int max = A[0],i=0;
    while(n > i){
        if(A[i] > max){max = A[i];}
        i++;
    }
    return max;
}

void randSave(int *A, int len){
    // int len = sizeof(A)/(int)sizeof(A[0]);
    // printf("len = %d\n",len);
    srand(time(NULL));
    for(int i=0;i<len;i++){
        A[i] = rand()%10;
        printf("%d ",A[i]);
    }
}

int main(){
    int n;scanf("%d",&n);
    int *num = (int*)malloc(sizeof(int)*n);
    printf("---------random making--------\n");
    randSave(num,n);
    // for(int i=0;i<n;i++)printf("%d ",num[i]);
    int max = currentMax(num,n);
    printf("\nmax = %d",max);
}