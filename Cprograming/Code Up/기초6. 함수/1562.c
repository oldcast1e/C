#include <stdio.h>

int n, m;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int min(int p, int q)
{
  return p>=q?q:p;
}
int main()
{
  scanf("%d%d", &n, &m);
  printf("%d\n", min(n, m));
}