#include<stdio.h>
int main(){
    
    int n;//입력받을 값
    int rst=0,sum=0;//첫번째 자리 저장 변수, 각 자리 수의 합 변수
    scanf("%d",&n);//n의 값을 입력받음

    while(n>0){//n이 양수일때 반복
        rst = n%10;//n의 나머지 연산
        sum += rst;
        n /=10;//n의 자리수를 낮춤=10으로 나눔
    }
    printf("%d",sum);//각 자리수의 합 출력
}