#include <stdio.h>
#include<stdlib.h>
int main() {
    long long int a = 0, b = 1,c, size;
    scanf("%lld",&size);
    long long int *fib = (long long int *)malloc(sizeof(long long int)*size+1);//동적할당
    fib[0] = 0, fib[1] = 1;/*피보나치 수열을 저장 전에 0,1세대 초기화*/
    for (long long int i = 2; i <= size; i++) { c = a + b; fib[i] = c; a = b; b = c;}
    printf("%lld",fib[size]);
    return 0;
}
