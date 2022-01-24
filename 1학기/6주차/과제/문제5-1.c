#include  <stdio.h>
int main(){//역수,역수 제곱
    int n,rst=0;//입력받을 정수와 결과값 선언
    scanf("%d",&n);//입력받음
    int sum=0,cnt;//결과값을 만들 변수 두개 선언
    while(n>0){

        sum *=10;//sum에 10을 곱해 나머지 연산된 값이 한자리 뒤에 더해지도록 함
        cnt = n%10;//나머지 연산을 이용해
        sum +=cnt;//sum에 더함
       
        n/=10;//n의 값을 줄임==반복위함
    }
    sum = sum*sum;//역수한 값을 제곱함
    printf("%d",sum);//결과값 출력
    
}