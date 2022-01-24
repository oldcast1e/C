#include<stdio.h>
int main(){

    int N,M;//양의 정수 입력
    scanf("%d %d",&N,&M);//두 개의 숫자 입력
    printf("%d\n",N>M?N/M:M/N);//N이 M보다 크면 N에서 M을 나눈 몫 출력, 아닌경우 M에서 N를 나눈 몫 출력
    printf("%d",N>M?N%M:M%N);///N이 M보다 크면 N에서 M을 나눈 나머지 출력, 아닌경우 M에서 N를 나눈 나머지 출력
    


}    