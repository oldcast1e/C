#include <stdio.h>

int n, k, d[1010];
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int lower_bound(int k){
    for(int i=1;i<=n;i++){
        if(d[i] >= k) return i;
    }return n+1;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);

  printf("%d\n", lower_bound(k));
}
/*
입력된 값보다 크거나 같은 값이 저장되어있는 처음 위치를 출력한다.
(입력된 값이 저장되어있는 모든 값보다 크면 n+1 을 출력한다.)
*/