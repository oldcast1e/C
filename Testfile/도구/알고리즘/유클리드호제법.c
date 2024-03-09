#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**[ 문제 6 ] 두 개의 양의 정수를 입력받아, 
이 두 정수의 최대공약수(gcd)를 유클리드 호제법으로 계산하여 출력하는 프로그램을 작성하시오.*/
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)

void gcd(int n,int m){
    int small,large;
    if(m == 0){printf("%d",n);return ;}
    small = (n>m?m:n);large = (n>m?n:m);
    gcd(small,large%small);
}
/**
두 개의 값이 들어온 경우, (작은 수) | (큰 수 % 작은 수)로 구현
 */
int main(){
    int n,m;scanf("%d %d",&n,&m);
    gcd(n,m);
}