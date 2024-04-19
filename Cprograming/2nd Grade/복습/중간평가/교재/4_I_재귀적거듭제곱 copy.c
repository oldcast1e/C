#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b){int tmp = *a; *a=*b;*b=tmp;}

int power(int a, int b){
    int I = 1;
    if(b%2 == 1) {I *= a; b --;}//b가 홀수인 경우
    if(b > 1){return a = a * (power(a, b- 1));}
    else return a * I;
    
}

int main(){
    int a,b;
    a = 4 , b = 4;
    printf("result = %d",power(a,b));
}