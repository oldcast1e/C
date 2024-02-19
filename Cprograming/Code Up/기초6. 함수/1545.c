#include <stdio.h>
#include <stdbool.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
bool zero(int k)
{
  return !k; //논리 연산자 !는 false(0)를 true(1)로, true(1)를 false(0)으로 만든다.
}
/*
0 이 입력되면 zero, 그 외에는 non zero 를 출력한다.
*/
int main()
{
  scanf("%d", &n);
  if(zero(n)) printf("zero");
  else printf("non zero");
  return 0;
}