#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//1부터 n까지 정수합 구하기: for문 사용하기

//연습문제7: 변수 i의 값이 n+1이 됨을 확인하기
int main(){
    int rst=0,n,i;
    puts("1부터 n까지의 합을 구합니다.");
    printf("n값 입력: "); scanf("%d",&n);
    for(i=1;i<=n;i++)rst += i;
    printf("i의 값: %d",i);
    
}
