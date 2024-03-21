#include <time.h>
#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;   

    long long int a = 0, b = 1,c, size;
    /*a: 2세대 전의 값 저장, b: 1세대 전의 값 저장*/
    scanf("%lld",&size);
    long long  int *fib = (long long int *)malloc(sizeof(long long int)*size);//동적할당
    fib[0] = 0, fib[1] = 1;/*피보나치 수열을 저장 전에 0,1세대 초기화*/
    for (int i = 2; i <= size; i++) {
        c = a + b;//앞의 두 항의 값의 합
        fib[i] = c; //배열에 저장
        a = b; b = c; //앞 두 항의 값 초기화
    }
    printf("%lld",fib[size]);


    //for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("\n프로그램 수행 시간 :%lf\n", (end-start));
}
/*
10
55
프로그램 수행 시간 :0.000070

20
6765
프로그램 수행 시간 :0.000076

30
832040
프로그램 수행 시간 :0.000090

40
102334155
프로그램 수행 시간 :0.000144

50
12586269025
프로그램 수행 시간 :0.000077
50
계산결과: 12586269025
반복횟수: 40730022147

60
1548008755920
프로그램 수행 시간 :0.000106
*/
