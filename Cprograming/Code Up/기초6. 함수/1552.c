#include <stdio.h>

double x;

double f(double x){
    return x-(int)x;
}

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
/*3.14159265358979*/
int main()
{
  scanf("%lf", &x);
  printf("%.14lf\n", f(x));
}