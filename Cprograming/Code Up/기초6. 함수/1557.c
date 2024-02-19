#include <stdio.h>

int n;

int f(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(n%i == 0)cnt++;
    }
    return cnt;
}

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int main()
{
  scanf("%d", &n);
  printf("%d\n", f(n));
}
//n의 약수의 개수를 출력한다.