#include <stdio.h>

int n, m, x;

int max(int p, int q){ return p>=q?p:q;}

int min(int p, int q){ return p<q?p:q;}
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int mid(int n, int m, int x){ 
    if((n>= m && m>=x) || (x>= m && m>=n)) return m;
    else if((m>= n && n>=x) || (x>= n && n>=m)) return n;
    else return x;

    return -1;
}

int main()
{
  scanf("%d%d%d", &n, &m, &x);
  printf("%d\n", mid(n, m, x));
}
/*
-2147483648 
-2147483648 
-2147483647
*/