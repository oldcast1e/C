#include<stdio.h>

int num[20];

int findmax(int n, int *max){
    if(num[n] > *max) *max = num[n];
    if(n >= 0){//맨 마지막 배열 요소부터 확인
        n --;
        return findmax(n, max);
    }
    return *max;
}
int main(){
    int n,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    max  = num[0];
    int rst = findmax(n,&max);
    printf("%d",rst);

} 
/*
5
4 1 8 3 7

*/