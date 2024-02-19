#include <stdio.h>
#include <stdbool.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
bool prime(int k)
{
  int i;
  for(i=2; i<k; i++)
    if(k%i == 0) //나누어 지면 중단 
      break;
  //k-1까지 모두 안 나뉘어져도 반복 중단 됨
  return i==k;
}
int main()
{
  scanf("%d", &n);
  if(prime(n)) printf("prime");
  else printf("composite");
  return 0;
}