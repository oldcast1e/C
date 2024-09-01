#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//양의 정수를 입력하고 입력된 정수의 자릿수를 출력하라.
int main(){
    int n,rst=0;
    printf("정수를 입력하세요: ");scanf("%d",&n);
    while(n>0){
        rst ++;
        n/=10;
    }
    printf("n의 자릿수는 %d 입니다.",rst);
}
