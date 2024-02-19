#include <stdio.h>

long long int n, m;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int f(long long int n,long long int m){
    if(n<m) return (long long int)(m-n);
    else return (long long int)(n-m);
}
int main()
{
  scanf("%lld%lld", &n, &m);
  printf("%lld\n", f(n, m));
}