#include <stdio.h>

long long int n;

int ksqrt(long long int n){
    long long int i = 0;
    while(1){
        if(i*i <= n && n < ((i+1)*(i+1))){
            return i;
        }
        else i++;
    }
    return 0;
}

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int main()
{
  scanf("%lld", &n);
  printf("%d\n", ksqrt(n));
  return 0;
    // printf("%lld",(long long int)sizeof(long long int));
}
//입력된 정수의 양의 제곱근의 정수부분만 출력한다.