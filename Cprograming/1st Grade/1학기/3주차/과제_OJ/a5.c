#include<stdio.h>
int main(){

    int N,a,b,c,rst=-1;//3자리 정수 N, 각 자리를 저장한 변수 a,b,c 결과값의 초기값을 -1로 선언
    //-1로 선언한 이유는 결과값이 -1이 나올수 없기 때문 
    scanf("%d",&N);//4자리 숫자 선언
    a = N/100; //100의 자리
    b = (N%100)/10;//10의 자리
    c = N%10;//1의 자리
    rst = (a>b && a>c?a:rst); //a가 가장 큰 경우 결과값은 a
    rst = (b>a && b>c?b:rst); //b가 가장 큰 경우 결과값은 b
    rst = (c>a && c>b?c:rst); //c가 가장 큰 경우 결과값은 c
    printf("%d",rst);


    



}