#include  <stdio.h>

int main() 
{
   int N;
   scanf("%d",&N); //N을 정의하고 값을 입력받는다.
   printf(N%2==0?"even":"odd");//N의 나머지 연산이 0인경우(2로 나눠떨어지는 경우=짝수) even
   //아니면 odd를 출력한다.

}