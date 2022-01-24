#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*양의 정수를 입력 받아, 각 자리의 수를 낮은 자릿수부터 차례로 출력하는 프로그램을 작성하시오.*/
void decimal(int n){
    printf("%d\n",n%10);
    n/=10;
    if(n>0)decimal(n);
}
int main(){
    int n;
    scanf("%d",&n);
    decimal(n);
}