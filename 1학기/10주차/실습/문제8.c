#include  <stdio.h>

int main(){
    
    int N,n,X[10],cnt;//입력받을 정수 N과 N을 대체할 변수 n과 크기가 10인 배열, 그리고 반복횟수(N의 숫자개수)
    scanf("%d",&N);//N을 입력받음
    n = N;//n에N을 저장
    while(N>0){//N이 0보다 큰 경우
        N/=10;//10으로 나누고
        cnt++;//cnt를 1증가(N의 자리수)
    }
    for(int i=0;i<cnt;i++){//cnt만큼 반복하여
        X[i] = n%10;//n의 10의 나머지(뒤부터)를 배열의 첫번쩨 요소부터 저장
        n/=10;//n을 10으로 나눠줌
    }
    for(int i=0;i<cnt;i++){//cnt번 반복하여
        printf(" %d",X[i]);//결과값 출력
    }
}
