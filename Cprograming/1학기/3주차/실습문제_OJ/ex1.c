#include<stdio.h>
int main(){

    int N;//임의의 정수 N선언
    int a,b,c,d,e; //0~5자리의 숫자 선언
    scanf("%d",&N); // 입력받음
    a = N/10000; // 첫번째 자리
    b = (N%10000)/1000;//두번째 자리
    c = (N%1000)/100;//세번째 자리
    d = (N%100)/10;//네 번째 자리
    e = N%10; // 5번째 자리
    printf("%dTTHO %dTHO %dHUN %dTEN %d",a,b,c,d,e);
}