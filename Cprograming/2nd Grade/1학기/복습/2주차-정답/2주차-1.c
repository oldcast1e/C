#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
[ 문제 1 ] 나머지 연산
‘%’(modulo) 연산자는 나눗셈의 나머지를 반환한다. 
덧셈과 뺄셈 연산자만을 사용하여 a를 b로
나눈 나머지를 반환하는 modulo(a, b) 함수와 
이를 테스트할 프로그램을 작성하시오. 단, a ≥ 0, b > 0 인 정수다.
*/

int modulo(int a,int b){
    return a%b;
}
/*
필요 함수:
◦ modulo() 함수
- 인자: 정수 a, b - 반환값: a % b
*/
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",modulo(a,b));

} 
