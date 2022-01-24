#include <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int fibonacci(int n) {//피보나치 함수 정의

    if (n == 0) return 0;
    else if (n == 1)return 1;//0,1인 예외적 상황
    else return fibonacci(n - 1) + fibonacci(n - 2);//예외적이 않은 상황에서 재귀함수

}
int main(){

    int n;//입력받을 정수값 선언
    scanf("%d", &n);//입력
    fibonacci(n);//함수 실행
    printf("%d ", fibonacci(n));//결과출력
    return 0;

}