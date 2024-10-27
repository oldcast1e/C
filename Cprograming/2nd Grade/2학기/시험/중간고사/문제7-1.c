#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(int *A, int *B, int sizeA, int sizeB){\
    int key, count = 0;
    // for(int j=0;j<sizeA;j++)printf(">>A key[%d] = %d\n",j,A[j]);
    for(int i=0;i<sizeB;i++){
        key = B[i];
        printf("B key[%d] = %d\n",i,key);
        for(int j=0;j<sizeA;j++){
            printf(">>A key[%d] = %d\n",j,A[j]);
            if(key == A[j]) return 1;
        }
    }
    return 0;
}

int main(){
    int n; scanf("%d",&n);
    int cnt = 0 ;
    int *num = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);

    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) rst[i] = -1;

    for(int i=0;i<n;i++){
        if(search(num,rst,n,cnt)==0){
            printf("None\n");
            rst[cnt] = num[i];
            cnt ++;
        }
        else num[i] = -1;
    }
    for(int i=0;i<cnt;i++) printf("%d ",rst[i]);

}
/*
5
100 170 130 150 100

*/