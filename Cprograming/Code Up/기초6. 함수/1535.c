#include <stdio.h>

int n, d[110];

// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int f(){
    int max = d[0],val = 1;
    for(int i=0;i<n;i++){
        if(max < d[i]){
            max = d[i];
            val = i + 1;
        }
    }
    return val;

}

int main()
{
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &d[i]);

  printf("%d", f());
  return 0;
}//가장 큰 값이 처음 나타나는 위치를 출력한다.