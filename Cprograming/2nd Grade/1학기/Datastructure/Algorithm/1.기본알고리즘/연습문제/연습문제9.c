#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//정수 a,b를 포함하여 그 사이 모든 정수의 합을 구하는 프로그램
int main(){
    int a,b,rst=0;
    printf("a의 값을 입력하세요: ");scanf("%d",&a);
    printf("b의 값을 입력하세요: ");scanf("%d",&b);
    for(int i=a;i<=b;i++) rst += i;
    printf("결과값은 %d 입니다.",rst);
    
}
