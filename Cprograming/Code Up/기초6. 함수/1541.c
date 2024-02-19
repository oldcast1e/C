#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
void f(int n){
    if(n < 0 )printf("negative");
    else if(n==0)printf("zero");
    else printf("positive");
}

int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}//음수(-) 가 입력되면 negative, 0 이 입력되면 zero, 그 외에는 positive 를 출력한다.