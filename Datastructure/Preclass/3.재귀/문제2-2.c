#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 작성하시오.*/
void decimal(int n){
    int dec=0,tmp=n,cnt=1;
    while(tmp>0){tmp/=10;dec++;}
    for (int i = 0; i < dec-1; i++) cnt*=10;
    printf("%d\n",n/cnt);
    n = n -(n/cnt)*cnt;
    if(n>0)decimal(n);
}
int main(){
    int n;
    scanf("%d",&n);
    decimal(n);
}