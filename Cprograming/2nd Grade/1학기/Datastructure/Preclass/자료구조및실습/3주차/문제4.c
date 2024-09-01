#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[ 문제 4 ] N 개의 정수를 입력 받아 (N ≤ 20), 
최댓값을 구하는 프로그램을 작성하시오.
*/
void cal(int *arr , int n, int *max){
    //n은 배열의 요소개수
    for(int i=0;i<n;i++)if(*max < arr[i]) *max = arr[i];
    if(n>0)cal(arr,n-1,max);
}
int main(){
    int n,*arr,max; 
    scanf("%d",&n); 
    
    arr = (int *)malloc(sizeof(int)*20);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);

    max = arr[n-1];
    cal(arr , n-1, &max);
    // printf
    printf("%d",max);
} 
/*
5
4 1 8 3 7
*/