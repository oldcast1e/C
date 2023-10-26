#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    long int a,r,n;
    scanf("%ld %ld %ld",&a,&r,&n);
    long  int rst = a; //printf(">>%d",rst);
    for(int i=0;i<n-1;i++) rst *= r;
    printf("%ld",rst);
    /*시작 값(a), 등차(d), 
    몇 번째인지를 나타내는 정수(n)가 입력될 때
    n번째 수를 출력하는 프로그램을 만들어보자.*/
 
} 