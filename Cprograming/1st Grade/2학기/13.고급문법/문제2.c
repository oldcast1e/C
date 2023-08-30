#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

void factorial(int N,double *prst){//오일러 수를 계산하는 함수
    double cal=1;//계산 값 초기화
    for(int i=1;i<=N;i++){//펙토리얼 계산
        cal *= i;
    }
    if(N>0){//N이0보다 크면
        *prst += 1/cal;//결과값 업데이트하고
        factorial(N-1,prst);//재귀함수 불러옴
    }
}

int main(){
    int N;//입력ㄱ밧
    double rst,*prst = &rst;////결과값 및 포인터 연결
    *prst = 0;//포인터 값 초기화
    scanf("%d",&N);//입력받기
    factorial(N,prst);//함수 실행
    printf("%.6lf",*prst+1);//결과 출력
}