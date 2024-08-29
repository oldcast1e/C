#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
[ 문제 4 ] N 개의 정수를 입력 받아 (N ≤ 20), 
    최댓값을 구하는 프로그램을 작성하시오.
*/


int findmax(int num[],int n, int *max){
    if(num[n] > *max) *max = num[n];
    if(n > 0){return findmax(num,n-1,max);}   
    else return *max;
    
}
int main(){
    int n,max,num[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    max = num[0];
    int rst = findmax(num,n,&max);
    printf("%d",rst);

} 
/*
5
4 1 8 3 7

*/