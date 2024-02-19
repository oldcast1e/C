#include <stdio.h>
long long signed int f()
{
  return -2147483649LL; //정수 값의 마지막에 LL을 붙이면 long long int 형을 나타냄
}
int main()
{
    printf("%lld", f() );
    return 0;
}