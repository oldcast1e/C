#include <stdio.h>

int main() {
   int min[100] ; //최솟값 저장 배열
   int max[100] ; //최댓값 저장 모든 배열 0으로 초기화
   int num[100];
   int n, tmp=0;//입력받을 횟수 n, 차례대로 비교하기 위한 tmp지정
   for (int i = 0; i < 100; i++) { //100번 반복하여
      min[i] = 1000;//각 배열에 100으로 저장(초기화)
   }
   for (int i = 0; i < 100; i++) { //100번 반복
      max[i] = -100;//각 배열에 -100으로 저장(초기화
   }

   scanf("%d", &n); //n을 입력받음
   int cnt = n; //출력 반복 횟수 변수 선언

   for (int i = 0; i < n; i++) { //n만큼 반복
      scanf("%d", &num[i]);//각각의 배열의 요소를  입력 받음

      min[i] = num[i]; //최댓값의 배열 값과 num배열 값을 같게 만듦
      max[i] = num[i]; //최솟값의 배열 값과 num배열 값을 같게 만듦
   }
   
   if (cnt % 3 != 0) cnt = cnt/3 + 1; //3으로 나누어지지 않는경우 3으로 나눈 후 +1
   else cnt = cnt / 3; //아닌 경우 나눈값 그대로 사용

   for (int i = n - 1; i >= 0; i--) { //반대로 배열을 불러
      printf("%d ", num[i]);//출력
   }
   

   while (n!=0) { //n이 0이 아닐때 까지 반복 - 무한루프
      
    for (int i = 0; i < cnt; i++) {//cnt 만큼 반복
        for (int j = 0; j < 3; j++) { //3번 반복

            if (max[tmp] > max[i]) //최댓값을 비교 하여
               max[i] = max[tmp];//최댓값에 저장

            if (min[tmp] < min[i]) //최솟값 비교하여
               min[i] = min[tmp]; //최솟값에 (배열) 지정
            
            tmp++;//tmp를 증가
            
         }
         min[i + 1] = 1000; //다음 최솟값 저장 요소 초기화
         max[i + 1] = -100; //다음 최댓값 저장 요소 초기화

         min[i + 2] = 1000; //다음 최솟값 저장 요소 초기화
         max[i + 2] = -100; //다음 최댓값 저장 요소 초기화
      }
      
      printf("\n"); //줄바꿈

      for (int i = 0; i <cnt; i++) { //cnt(출력) 할 횟수 만큼 반복
         printf("%d ", max[i]); //출력
      }

      printf("\n"); //줄바꿈
      for (int i = 0; i < cnt; i++) { // cnt(출력) 할 횟수 만큼 반복
         printf("%d ", min[i]);//출력
      }

      if (cnt == 1) break;//cnt가 1이면 반복문 탈출

    
      if (cnt % 3 != 0) cnt = cnt / 3 + 1; //3으로 나눠지지 않는 경우 3으로 나눈 값에 1을 더함
      else cnt = cnt / 3; //3으로 나눠지는 경우 cnt를 3으로 나눈 값으로 설정
      
      tmp = 0;//tmp값 초기화
   }

}