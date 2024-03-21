#include <stdio.h>
#include<stdlib.h>
int main() {
int a = 0, b = 1,c, size;
scanf("%d",&size);
int *fib = (int *)malloc(sizeof(int)*size+1);//동적할당
fib[0] = 0, fib[1] = 1;/*피보나치 수열을 저장 전에 0,1 세대 초기화*/ 
for (int i = 2; i <= size; i++) { c = a + b; fib[i] = c; a = b; b = c;} 
printf("계산결과: %d",fib[size]);
return 0;
}