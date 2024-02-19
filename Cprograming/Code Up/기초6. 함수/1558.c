#include <stdio.h>

long long int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
long long int  f(long long int n){
    long long int size = 0,tmp=n;
    while(tmp > 0){
        tmp/=10;
        size ++;
    }
    // printf("size = %lld",size);
    tmp = 0;
    for(long long int i=0;i<size;i++){
        tmp += n%10;
        tmp *=10;
        n/=10;
    }tmp/=10;
    return tmp;
}
int main()
{
  scanf("%lld", &n);
  printf("%lld\n", f(n));
    // printf("%d",sizeof())
}