#include <stdio.h>

int n, m;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int f(int p, int q)
{
  return (long long int)p+q; //주의! 그냥 합하면 int형으로 계산됨 
}
int main()
{
  scanf("%d%d", &n, &m);
  printf("%lld\n", f(n, m));
}