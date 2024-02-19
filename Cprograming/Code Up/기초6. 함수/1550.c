#include <stdio.h>

long long int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int sqrt(long long int n){
    long long int i = 1;
    int val=0;
    while(n>=i){
        if(i*i >= n){
            val = i;
            break;
        }
        else i ++;
    }
    return val;
}
/*입력된 정수의 양의 제곱근의 정수부분만 출력한다.*/
int main()
{
  scanf("%lld", &n);
  printf("%d\n", sqrt(n));
  return 0;
}