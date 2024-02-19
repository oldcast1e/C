#include <stdio.h>

int n, a, b, d[1010];
int maxi(int a,int b){
    int max = d[a],index=a;
    for(int i=a;i<=b;i++){
        if(max < d[i]){
            max = d[i];
            index = i;
        }
    }
    return index;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d%d", &a, &b);

  printf("%d\n", maxi(a, b));
}

//입력된 데이터 배열의 [a, b] 구간에서 최대값이 처음 나타나는 위치를 출력한다.