#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
void f(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(n%i==0) cnt ++;
    }
    if(cnt == 2)printf("prime");
    else printf("composite");
}
/*
소수(prime)가 입력되면 prime, 
합성수(composite)가 입력되면 composite 를 출력한다.
*/
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}