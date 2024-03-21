#include <stdio.h>
#include <time.h>
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
     int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;   

    long long int n; scanf("%lld",&n);
    printf("계산결과: %lld\n",rFibonacci(n));
    printf("반복횟수: %lld",cnt);

    //for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("\n프로그램 수행 시간 :%lf\n", (end-start));
}