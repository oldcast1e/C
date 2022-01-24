#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**[ 문제 6 ] 두 개의 양의 정수를 입력받아, 
이 두 정수의 최대공약수(gcd)를 유클리드 호제법으로 계산하여 출력하는 프로그램을 작성하시오.*/
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)

void gcd(int *n,int *m){
    int tmp;
    if(*n > *m) swap(tmp,*n,*m);//*n이 더 작은 수가 되도록 변환
    if(*n == 0 || *m == 0) return ;
    gcd(n,*m/(*m));
}
/**
두 개의 값이 들어온 경우, (작은 수) | (큰 수 % 작은 수)로 구현
 */
int main(){
    int n,m,*pn = &n,*pm = &m;scanf("%d %d",&n,&m);
    gcd(pn,pm);
    printf("%d",*pn);



}