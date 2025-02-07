#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;scanf("%d",&n);
    int *num = (int*)malloc(sizeof(num)*n+1);

    for(int i=0;i<n;i++){scanf("%d",&num[i]);}

    // for(int i=0;i<n;i++){printf("%d ",num[i]);}printf("\n");


    int max,maxdir,tmp;
    for(int i=0;i<n-1;i++){
        max = num[0]; maxdir = 0;
        /*
        10개의 요소가 있을때, 첫번째 요소부터 각가 10,9,8...번째 요소까지 10번 순회
        */
        for(int j=0;j<n-i;j++){if(max < num[j]){max = num[j]; maxdir = j;}} 
        // printf("[%d] in %d\n",max,maxdir);
        
        tmp = num[n-i-1]; 
        num[n-i-1] = num[maxdir]; 
        num[maxdir] = tmp;
        // for(int i=0;i<n;i++){printf("%d ",num[i]);} printf("\n")
        ;
    }
    for(int i=0;i<n;i++){printf("%d ",num[i]);}
}
/*
8
8 31 48 73 3 65 20 29
*/