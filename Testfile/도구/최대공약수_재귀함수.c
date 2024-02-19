#include <stdio.h>
int gcd(int p, int q){ if(p==0) return q; return gcd(q%p, p);}

int lcm(int a,int b){
    int min = a>b?b:a;
    while(1){
        if(a %min ==0 && b%min ==0) return min;
        else min --;
    }
    return -1;
}
int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%lld\n", gcd(a, b));
}