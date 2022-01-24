#include <stdio.h>

int main()
{
   int x, cnt = 0,tmp; //입력받을 x와 횟수를 측정할 cnt선언, 변수를 바꿀 tmp 변수 선언
   int num1[100]; //크기 100인 배열 선언
   int num2[100]; //크기 100인 배열 선언
   int size1, size2; //배열 크기 저장 변수 선언 

   while (1) { //무한루프
      scanf("%d", &x); //값을 입력받음
      if (x < 0) break; //종료조건인 경우 반복문 종료

      num1[cnt] = x; //입력받은 값을 배열에 넣고
      cnt++; //1증가
      size1 = cnt;//개수 저장
   }

   cnt = 0; //다음 배열을 입력받음

   while (1) { //무한루프
      scanf("%d", &x); //값을 입력받음
      if (x < 0) break; //종료조건인 경우 반복문 종료

      num2[cnt] = x; //입력받은 값을 배열에 넣고
      cnt++; //1증가
      size2 = cnt; //개수 저장
   }
   ////////

   for (int i = 0; i < size2; i++) { // 두 번째 배열 개수만큼 반복
      num1[size1] = num2[i]; //배열을 하나로 합함(num1의 뒤부터)
      size1++;
   }

   // 중복 제거
   for (int i = 0; i < size1; i++) {  //두 배열 더한 크기만큼 반복
      for (int j = i + 1; j < size1; j++) {  //j=i+1로 시작하여 현재 숫자와 다른 숫자를 비교(앞)
         if (num1[i] == -1) { //-1이면 중복이므로 (ㄴ)
            continue;//continue
         }
         if (num1[i] == num1[j]) { //같으면
            num1[j] = -1; //-1로 중복 표시하기 (ㄱ)
         }
      }
   }

   // 오름차순 정리 
   for (int i = 0; i < size1; i++) { //두 배열 합한 크기만큼 반복
      for (int j = i + 1; j < size1; j++) { //j=i+1로 시작하여 현재 숫자와 다른 숫자를 비교(앞)
         if (num1[i] > num1[j]) { //앞의 수가 더 크면
            
            tmp = num1[i]; //tmp에 저장
            num1[i] = num1[j]; //순서변환
            num1[j] = tmp; //순서변환
         }
 
      }
   }


   for (int i = 0; i < size1; i++) { //두 배열 합한 크기만큼 반복
      if (num1[i] < 0) continue; //-1이면 중복으로 설정했으므로 양수인경우 
      printf(" %d", num1[i]);//출력하기
   }

   return 0;//종료
}