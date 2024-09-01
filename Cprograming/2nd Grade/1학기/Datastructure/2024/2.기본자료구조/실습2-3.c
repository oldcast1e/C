#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num = 10;
    int *arr = (int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++)scanf("%d",&arr[i]);
    for(int i=0;i<num;i++)printf("%d ",arr[i]);

    
} 
/*

*/