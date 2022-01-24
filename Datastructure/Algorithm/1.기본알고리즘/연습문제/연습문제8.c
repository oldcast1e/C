#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//가우스 덧셈이용 1부터 n까지의 정수합을 구하는 프로그램을 작성하라.
//가우스 덧셈이용: n(n+1)/2
int main(){
    int n,rst;
    printf("정수를 입력하세요: ");scanf("%d",&n);
    rst = n*(n+1)/2;
    printf("결과값: %d",rst);
    
}
