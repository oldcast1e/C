#include <stdio.h>
int main()
{
   int n, m, i, sum=0, cnt; // 정수형 변수 선언 
   scanf("%d %d",&n,&m); //정수 2개 입력받음
   if (n < m) { // 큰 값이 n, 작은 값 m이 되도록 치환
      cnt = n; //임시 저장 변수
      n = m; 
      m = cnt; 
   }
   if (0 > m && 0 < n ) { // 두 수 중 하나만 음수일 때 

      i = n + m;//더해야 하는 횟수 저장
      if (i < 0) { // 절댓값이 큰 수가 음수일 인 경우= 음수인 수가 더 절대값이 커야 더한 값이 음수
         i *= -1; //횟수를 양수로 변환
         for (int j = 0; j < i; j++) { //횟수 만큼 반복
            sum += m; // sum값에  더하기
            m++; // 더하는 값 증가
         }
      }
      else { // 절댓값이 큰 수가 양수 일 때
         for (int j = 0; j < i; j++) { //횟수 만큼 반복
            sum += n; // sum값에 누적해서 더하기
            n--; // 더하는 값 감소
         }
      }
   }
   else { // 두 수의 부호가 같을 때
      i = n - m + 1;  // 더해야 하는 횟수
      for (int j = 0; j < i; j++) { //횟수 만큼 반복
         sum += n; //sum에 더하기
         n--;  // 더하는 값 감소
      }
   }
   printf("%d", sum);// 결과 출력
}