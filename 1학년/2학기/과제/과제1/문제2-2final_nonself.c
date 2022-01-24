#include <stdio.h>
int passengerN(int n) {//정수를 인자로 받음
   if (n < 5)return -1;//5보다 작으면 -1반환
    else return 0;//아니면 0반환
}
int changeseat(int *arr) {//배열을 인자로 받는 changeseat 선언
   int rst=1, key =1;
   for (int i = 1; i <= 21; i++) {
      key  = 1;
      for (int *p = arr;p<arr+21; p++)if (i == *p)key  = 0; //중복된 수 존재 시 조건값을 0으로
      if (key  == 1) return i; //중복이 없을 경우 해당 순서 = 요소를 반환
   }
   return rst;//조건불만족시 1
}
void rebooking(int *arr) {//배열을 인자로 받는 rebooking함수 선언

   int num;
   for (int *p = arr; ; p++) {//배열을 검토 ... ㄱ
      if (*p == 0) break;//해당 배열 요소가 0인 경우 = (승객의 예약 확인이 끝난 경우) 종료

      for (int *j = p + 1; ; j++) { // ㄱ보다 한 칸 뒤부터 반복하여 배열 검토
         if (*j == 0) break;//해당 요소가 0인 경우 종료

         if (*p == *j) {//중복 발생
            num = (int)changeseat(arr);//changeseat함수 실행
            //printf("n=%d\n",num);
            *j = num;
         }
      }
   }
}
int main() {
   int N, psgnum;//입력받을 정수와 운행여부 변수 선언
   int arr[21] = {0};//크기 21의 배열 선언
   scanf("%d", &N);// 승객을 입력받음
   for (int *p = arr; p < arr + N; p++) {//승객 수만큼 반복
      scanf("%d", p);//입력받음
   }
   psgnum = passengerN(N);//운행 여부 값 저장
   printf("%d\n", psgnum);//운행 여부 출력
   
   if (psgnum == 0) {//승객의 수가 충분한 경우
      rebooking(arr);//rebooking함수 실행
      for (int *p = arr; p < arr + N; p++)printf("%d ", *p);//결과값 출력 //승객수 만큼 반복
   }
}