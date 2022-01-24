#include <stdio.h>
int main()
{
    int A[20];
    int f, r, m; //입력받을 정수 선언
   int tmp1,tmp2;//교환 시 사용할 변수

   for(int i=1;i<=20;i++){//20번 반복하여
        A[i-1] = i;//배열에 1~20까지 저장
    }
   scanf("%d %d %d", &f, &r, &m); //f,r,m 입력받음

   tmp1 = A[r - m + 1]; //shift 첫 숫자 빈공간 저장
   A[r - m + 1]=A[r]; //맨 뒤 수 넣기

   for (int i = 1; i < m; i++) { //교환할 횟수만큼 반복
      tmp2 = A[r - m + 1 + i]; //그다음 넣을 값 빈 tmp2에 저장
      A[r - m + 1 + i] = tmp1; //저장해 놓은 tmp1 그 다음 자리에 대입
      tmp1 = tmp2; //tmp1에 tmp2 값 이동
   }

   for (int i = 0; i < 20; i++) { //결과값 출력
      printf("%d ", A[i]);//
   }

}