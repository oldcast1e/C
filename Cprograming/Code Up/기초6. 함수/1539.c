#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
void f(int n){
    if(n==0)printf("false");
    else printf("true");
}

int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}//0 이 입력되면 false, 그 외에는 true를 출력한다.