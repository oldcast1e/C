#include <stdio.h>

int a, n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int kpow(int a,int n){
    if(a==1) return 1;
    long long int val = 1;
    for(int i=0;i<n;i++) val *= a;
    return (long long)val;
    
}

int main()
{
  scanf("%d%d", &a, &n);
  printf("%lld\n", kpow(a, n));
}
/*
2305843009213693952
2305843009213693952
*/