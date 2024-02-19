#include <stdio.h>

int n, m;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int max(int p, int q)
{
  return p>=q?p:q;
}

int main()
{
  scanf("%d%d", &n, &m);
  printf("%d\n", max(n, m));
}
