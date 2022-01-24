#include<stdio.h>

int multiple(int x, int y) {//multiple 함수 선언
   if (x % y == 0) return 1; //x가 y의 배수이면 1반환
   else return 0;//아니먄 0반환
}
int maximum(int x, int y) {//maximum 함수 선언
   if (x >= y)//x가 y보다 크면
      return x;//x반환
   else//크지 않으면
      return y;//y반환
}
int digit_maximum(int x) {//digit_maximum 함수 선언
   int max = -1;//최대값 -1로 초기화
   while (x > 0) {//x가 0보다 클 동안 반복

      int fn = x % 10;//마지막 자릿수를 fn에 저장
      if (maximum(fn, max) > max)//fn이 max보다 큰 경우
         max = maximum(fn, max);//max값을 fn로
      x /= 10;//x을 10으로 나눔//반복키위함
   }
   return max;//max값 반환
}
int main() {//main함수
   int n, m, k;//정수 n,m,k
   scanf("%d %d %d", &n, &m, &k);//n,m,k 입력
   int max1 = -1;//max1 초기화
   int max2 = -1;//max2 초기화
   for (int i = n; i <= m; i++) {//n이상 m이하일때 반복
      if (multiple(i, k) == 1) {//i가 k의 배수이면

         if (max1 < digit_maximum(i))//max1이 i의 자릿수중 최댓값보다 크면
            max1 = digit_maximum(i);//max1 교체
      }
      else {//배수가 아닌경우
         max2 = maximum(max2, i % k);//max2는 max2와 i를 k로 나눈 나머지중 큰 수
      }
   }
   printf("%d", maximum(max1, max2));//결과값 출력

}