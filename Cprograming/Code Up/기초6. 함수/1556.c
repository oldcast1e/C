#include <stdio.h>

int n;
long long int f(int n){
    long long int val = 1;
    for(int i=1;i<=n;i++){
        val *= i;
    }
    return val;
}


// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}