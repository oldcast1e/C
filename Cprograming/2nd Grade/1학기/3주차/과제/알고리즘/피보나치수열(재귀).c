#include<stdio.h>
long long int cnt = 0;
long long int rFibonacci(int n){
    cnt ++;
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else {return rFibonacci(n - 1) + rFibonacci(n - 2);}
}
int main(){
    long long int n; scanf("%lld",&n);
    printf("계산결과: %lld\n",rFibonacci(n));
    printf("반복횟수: %lld",cnt);
}
