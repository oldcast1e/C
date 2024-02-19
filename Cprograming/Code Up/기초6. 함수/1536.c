#include <stdio.h>

int n;

long long int d[110];

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int f(){
    long long int min = d[1];
    for(int i=1;i<=n;i++){
        if(min > d[i]){
            min = d[i];
        }
    }
    return min;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%lld", &d[i]);

  printf("%lld", f());
  return 0;
}//가장 작은 값을 출력한다.