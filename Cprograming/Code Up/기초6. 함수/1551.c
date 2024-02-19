#include <stdio.h>

int n, d[100010], k;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int f(int k){
    for(int i=1;i<=n;i++){
        if(d[i]==k) {
            return (i);
        }
    }
    return -1;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);
  printf("%d\n", f(k));
}