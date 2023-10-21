#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b; scanf("%d %d",&a,&b);
    printf("%d",a<<b);
}
/*
 printf("%d", a<<1); //10을 2배 한 값인 20 이 출력된다.
    printf("%d", a>>1); //10을 반으로 나눈 값인 5 가 출력된다.
    printf("%d", a<<2); //10을 4배 한 값인 40 이 출력된다.
    printf("%d", a>>2); //10을 반으로 나눈 후 다시 반으로 나눈 값인 2 가 출력된다.
    */