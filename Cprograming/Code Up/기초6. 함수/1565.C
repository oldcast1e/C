#include <stdio.h>

int gcd(int p, int q){ if(p==0) return q; return gcd(q%p, p);}

long long int lcm(int p, int q){ 
    long long int val = gcd(p,q);
    return (long long int)(val * (p/val*q/val));
}

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%lld\n", lcm(a, b)); 
}