#include <stdio.h>
long long int mmz[100];
long long int cnt = 0;
long long int rFibonacci(int x){
  cnt ++;
    if(x <= 2){return 1;}
    if(mmz[x] != 0){return mmz[x];}
    else{
        mmz[x] = rFibonacci(x-1) + rFibonacci(x-2);
        return mmz[x];
    }
}

int main(){
    long long int n; scanf("%lld",&n);
    printf("계산결과: %lld\n",rFibonacci(n));
    printf("반복횟수: %lld",cnt);
}