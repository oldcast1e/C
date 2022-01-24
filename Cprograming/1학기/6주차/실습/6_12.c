#include<stdio.h>
int main(){
    
    int n;//입력받을 값
    int rst=0,cnt=0;//첫번째 자리 저장 변수, 3의 횟수 카운트 변수
    scanf("%d",&n);//n의 값을 입력받음

    while(n>0){//n이 양수일때 반복
        rst = n%10;//n의 나머지 연산=3이있는지 확인
        if(rst==3)
            cnt ++;//3인 경우 카운트를 1올림
        n /=10;//n의 자리수를 낮춤=10으로 나눔
    }
    printf("%d",cnt);//3이 나온 횟수 출력
}