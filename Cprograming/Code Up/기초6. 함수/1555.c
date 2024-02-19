#include <stdio.h>

int n;

long long int f(int n){
    long long int val=0;
    for(int i=1;i<=n;i++){
        val += i;
    }
    return val;
}

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}
/*
int 형 정수(n)가 입력된다.
(1 <= n <= 10000000)

1부터 n까지의 정수합을 출력한다.
*/