#include <stdio.h>

int n, k, d[1010];
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int findi(int k){
    // int idx = -1;
    for(int i=1;i<=n;i++){
        if(d[i] == k) return i;
    }return -1;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);

  printf("%d\n", findi(k));
}