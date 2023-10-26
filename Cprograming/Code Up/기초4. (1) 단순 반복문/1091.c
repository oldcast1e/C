#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    signed long int a,m,d,n,rst;
    scanf("%ld %ld %ld %ld",&a,&m,&d,&n);
    rst = a;
    for(int i=1;i<n;i++){
        rst = rst * m + d;
    } printf("%ld",rst);
} 
/*
예를 들어
1 -1 3 -5 11 -21 43 ... 은
1부터 시작해 이전에 만든 수에 -2를 곱한 다음 1을 더해 다음 수를 만든 수열이다.
*/