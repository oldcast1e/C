#include <stdio.h>

int n, a, b, d[1010];
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int subsetsum(int a,int b){
    long long int rst = 0;
    for(int i=a;i<=b;i++){
        rst += d[i];
    }return (long long int)rst;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d%d", &a, &b);

  printf("%lld\n", subsetsum(a, b));
}