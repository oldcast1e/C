#include <stdio.h>
// #include <stdlib.h>

long long int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int abs(long long int n){
    if(n < 0)n*=-1;
    return n;
}
/*입력된 정수의 절댓값을 출력한다.*/
int main()
{
  scanf("%lld", &n);
  printf("%lld\n", abs(n));
  return 0;
}