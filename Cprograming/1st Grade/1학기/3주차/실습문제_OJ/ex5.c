#include<stdio.h>
int main(){

    double N,R,S;//원의 둘레 실수 N
    double pi = 3.14;
    scanf("%lf",&N);//입력받음
    R = N/(2*pi);//R을 정의(N = 2*pi*R 이용)
    S = pi*R*R;//원의넓이
    printf("%.0lf",S);//출력

    


}    