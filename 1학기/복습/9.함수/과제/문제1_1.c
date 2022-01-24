#include <stdio.h>

int convert_bottom(int N) {//짝수일때 필요한 함수 정의
   char r;//출력할 문자형 변수
   r = N % 100;//뒤에 두자리 수
   if (N % 100 == 0) printf("*"); //아스키 코드0이 null값 ->*출력
   else if ((r >= 'a'&&r <= 'z') || (r >= 'A'&&r <= 'Z'))//소문자나 대문자면
      printf("%c", r); //문자 출력
   else printf("*"); //* 출력

   return N / 100;//뒤를 제외한 앞의 자리 수 반환
}

int num_digit(int N) { //int num_digit 함수 정의
   int m = N;//자리수 판정을 위한 N과 같은 m 만들기
   int t=0;//자리수 초기화
   while (1) {//무한루프
      if (m == 0) break;//더이상 남아있는 자리수가 없을때 빠져나오기
      m /= 10;//10으로 나눠주기
      t++;//자릿수 누적
   }
   return t;//자리수 t반환
}


int convert_top(int N, int t) { // N이 홀수일때 사용할 함수 정의
   char r;//프린트할 문자형 변수 r 지정
   int k = 1;//앞의 두 자리를 제외한 나머지 수를 구하기 위한 k지정
   if (t == 1) {//마지막 자리일때 
      printf("*");//*출력 후 
      return 0;//0반환
   }
   else {
      t -= 2;//앞 두자리 제외한 만큼의 횟수
      while (1) {//무한루프
         if (t == 0) break;//횟수만큼 돌리면 빠져나오기
         k *= 10; //횟수-2만큼 10곱해주기
         t--;//횟수 줄여주기
         //printf("%d\n", k);//확인용
      }
      //printf("%d\n", N - (N % k)); //확인용
      r = (N - N % k) / k; //앞 두 자리 수 
      if ((N - N % k) / k == 0) printf("*"); //아스키 코드0이 null값 ->*출력
      else if ((r >= 'a'&&r <= 'z') || (r >= 'A'&&r <= 'Z'))//소문자나 대문자면
         printf("%c", r);//문자 출력
      else printf("*");//아니면 *출력
      return N % k;//뒤의 자릿수 숫자 반환
   }
}


int main()
{
   int N; //변수 N
   scanf("%d", &N); //입력
   
   int odd = 0;//홀수 인지 아닌지 판별용 변수
   int c = num_digit(N);//자릿수 변수 지정
   if (num_digit(N) % 2 == 0) {
      odd = 1; //짝수면 1
   }
   

   while (odd==0) {//홀수면
      
      if (N == 0&&c==0) break; //끝자리 까지 돌리면 빠져나오기
      N = convert_top(N, c); //함수 돌리기
      if (c == 1) c = 0;
      else
      c -= 2;//자릿수 초기화
   }

   while (odd == 1) {//짝수면
      if (N == 0) break; //끝자리까지 돌리면 빠져나오기      
      N = convert_bottom(N); //함수 돌리기
   }
   
   
   return 0; //종료
}