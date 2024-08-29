#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b){int tmp = *a; *a=*b;*b=tmp;}
//2개의 자연수 또는 정식(整式)의 최대공약수를 구하는 알고리즘
void gcd(int a, int b){
    printf("a= %d | b = %d\n",a,b);
    if(a < b) swap(&a,&b);

    if(a == 0 || b == 0) printf("%d",a!=0?a:b);
    else gcd(a%b,b);
}

int main(){
    gcd(28,21);
}