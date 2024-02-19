#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int zero(int n){
    int val = n==0?1:0;
    return val;
}
int plus(int n) {
    int val = n>=0?1:0;
    return val;
}
/*양수인 경우 plus, 음수인 경우 minus, 0 인 경우 zero를 판별하여 출력하시오.*/
int main()
{
  scanf("%d", &n);
  if(zero(n)) printf("zero");
  else printf("%s", plus(n)?"plus":"minus");
  return 0;
}