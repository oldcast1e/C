#include <stdio.h>

double x;

long long int f(double x)
{
  long long int t=(long long int)x;

  if(t<x)
    return x+1;
  else
    return x;
}

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int main()
{-1.1
  scanf("%lf", &x);
  printf("%lld\n", f(x));
}