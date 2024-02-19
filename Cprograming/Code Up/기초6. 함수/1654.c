#include <stdio.h>

int a, b;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int gcd(int a,int b){
    int min = a>b?b:a;
    while(1){
        if(a %min ==0 && b%min ==0) return min;
        else min --;
    }
    return -1;
}
int main()
{
  scanf("%d%d", &a, &b);
  printf("%d\n", gcd(a, b));
}
/*
두 개의 자연수(a, b)가 공백을 두고 입력된다.
(1 <= a,b <= 100000)

160 96
32
*/