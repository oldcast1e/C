#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
void f(int n){
    for(int i=0;i<n;i++)printf("love\n");
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}