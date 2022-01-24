#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>

#define val(a) (a>0) ? a:-a//매크로 함수
#define MAX(a,b) (val(a)) > (val(b)) ? a : b//매크로 함수
int main() {//main 함수
   int ar[6];//배열 선언
   scanf("%d %d %d %d %d %d", &ar[0], &ar[1], &ar[2], &ar[3], &ar[4], &ar[5], &ar[6]);//ar배열 입력
   int m = MAX(ar[0],ar[1]);//큰 수 저장
   for (int i = 2; i <= 5; i++) {
      m = MAX(m, ar[i]);//하나씩 비교하면서 큰 수 찾기
   }
   printf("%d %d", m, val(m));//출력
}
