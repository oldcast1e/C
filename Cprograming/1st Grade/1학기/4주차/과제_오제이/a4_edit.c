#include <stdio.h>

int main()
{
   char u, rst; //입력받는 문자,결과값 선언
   int a, L = ('Z' - 'A' + 1); //알파벳 총 개수 26 고정

   scanf("%c", &u); 
   scanf("%d", &a); //각각의 문자와 숫자를 입력받음

   if ('A'<=u && u <= 'Z') {  
      rst = (u + a - 'A') % L + 'A'; //입력받은 문자가 A,Z사이인경우
      printf("%c", rst); //각 문자(숫자)와 숫자를 더한 값에 A를 뺌 = A,Z에서 (u+a)번째 숫자
      }//나머지 연산으로 나눠주면 아스키코드의 값이 넘어서도 원래의 순서를 가짐
      //'A'를 더해줘 원래의 위치값으로 돌림
      
   
   else if ('a' <= u && u <= 'z') { //입력받은 문자가 a,z사이인경우
      rst = (u + a - 'a') % L + 'a';   //각 문자(숫자)와 숫자를 더한 값에 a를 뺌 = A,Z에서 (u+a)번째 숫자
      printf("%c", rst);    
      }//나머지 연산으로 나눠주면 아스키코드의 값이 넘어서도 원래의 순서를 가짐
      //'a'를 더해줘 원래의 위치값으로 돌림

   else
      printf("%c",u);  //아무것도 충족하지 않는경우 입력받은 문자를 그대로 출력

}