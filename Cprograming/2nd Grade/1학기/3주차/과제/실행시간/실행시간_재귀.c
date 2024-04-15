#include <time.h>
#include <stdio.h>
long long int cnt = 0;
long long int rFibonacci(int n){
    cnt ++;
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else {return rFibonacci(n - 1) + rFibonacci(n - 2);}
}

int main(void)
{
    int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;    


    long long int n; scanf("%lld",&n);
    printf("계산결과: %lld\n",rFibonacci(n));
    printf("반복횟수: %lld\n",cnt);

    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end-start));
}
/*
10
계산결과: 55
반복횟수: 177
프로그램 수행 시간 :0.000130

20
계산결과: 6765
반복횟수: 21891
프로그램 수행 시간 :0.000184

30
계산결과: 832040
반복횟수: 2692537
프로그램 수행 시간 :0.010890

40
계산결과: 102334155
반복횟수: 331160281
프로그램 수행 시간 :1.136636

50
계산결과: 12586269025
반복횟수: 40730022147
프로그램 수행 시간 :86.443851
*/