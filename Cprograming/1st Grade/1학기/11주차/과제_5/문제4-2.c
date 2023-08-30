#include<stdio.h>
int is_prime_number(int n) { //소수 판별 함수 정의
   int cnt = 0;//소수 등장 횟수 저장 변수 
   int rtr = 0;//return 값 저장 변수

   for (int i = 1; i <= n; i++) {//n번 반복하여
      if (n%i == 0) cnt++;//약수 개수 확인
   }

   if (cnt == 2) rtr = 1;//cnt==2이면 (=소수이면) 1반환
   return rtr;//아니면 0 반환
}

int count_prime_number(int cnt, int num) { //소수의 개수 세는 함수 정의

   int rst = is_prime_number(num);//소수 판별 값 저장

    cnt = (num<100 && rst==1?cnt+1:0);
   return cnt; //개수 반환
}
int main() {

   int n,rst;//반복횟수
   int num[100];//수를 입력받을 배열 지정

   int cnt=0;//개수를 0으로 초기화
   int max = 0,result=0;//max값 초기화
   scanf("%d", &n);//입력받음
   for (int i = 0; i < n; i++) { //반복횟수만큼 반복
      scanf("%d", &num[i]);//배열 요소 입력
   }
   
   for (int i = 0; i < n; i++) {//배열 입력된 만큼
      cnt = count_prime_number(cnt, num[i]);//약수개수 판별 함수 실행
      if (max < cnt) {//cnt개수가 최대인 경우
         max = cnt;//max값 바꾸기
         result = num[i];//결과값 바꾸기
      }
   }
   printf("%d\n", max);//출력
   if (result != 0) //소수가 없으면
   printf("%d", result);//출력
   return 0;//종료
}

