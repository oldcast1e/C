#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*

[ 문제 6 ] 두 개의 양의 정수를 입력받아, 
이 두 정수의 최대공약수(gcd)를 유클리드 호제법으로 
계산하여 출력하는 프로그램을 작성하시오.

gcd(12, 8)
= gcd(8, 12%8) 
= gcd(8,4) 
= gcd(4, 8%4) 
= gcd(4,0)
*/
void swap(int *n,int *m){
    int tmp  = *n; *n = *m; *m = tmp;
}

int gcd(int n,int m){
    //n이 m보다 크도록 수정
    if(n<m){swap(&n,&m);}
    if(n != 0 && m !=0){
        // printf("%d %d\n",n,m);
        return gcd(m,n%m);
    }
    else return(n==0?m:n);
}
int main(){
    int n,m; scanf("%d %d",&n,&m);
    printf("%d",gcd(n,m));
} 
/*

*/