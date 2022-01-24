#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {//함수 정의 
   int n;//변수 선언 
   scanf("%d", &n); getchar();//입력받기 
   char x[101], tmp[101];//변수 선언 
   gets(x);//입력 받기 

   char** y = NULL;//변수 선언 
   y = (char**)malloc(n * sizeof(char*));// 메모리 동적 할당

   for (int i = 0; i < n; i++) {//n번 반복
      gets(tmp);//입력 
      y[i] = (char*)malloc(strlen(tmp) * sizeof(char));//동적할당
      strcpy(y[i], tmp);//저장
   }
   int cnt = 0,max_cnt = 0,max = 0;//변수 선언 
   char max_arr[101] = { 0 };//변수 선언 

   for (int i = 0; i < n; i++) {//n번 반복
      for (int j = 0; j < strlen(y[i]); j++) {//y의 길이만큼 반복 
         for (int k = 0; k < strlen(x); k++) {//x의 길이만큼 
            if (y[i][j+k] == x[k]) {//조건 만족시
               cnt++;//매개변수 증가 
            }
            if (cnt == strlen(x)) {////조건 만족시 == x의 단어가 있으면 
               cnt = 0;//초기화 
               max_cnt++;//매개변수 증가 
               j += strlen(x)-1;//중복 제외 위함 
            }
         }
         cnt = 0;//초기화 
      }
      
      if (max < max_cnt) {//조건을 만족하면 
         max = max_cnt;//초기화 
         strcpy(max_arr, y[i]);//복사 
      }
      max_cnt = 0;//초기화 
   }
   char none[5] = "NONE";//변수 선언 
   if (max == 0) printf("%s", none);//없으면 none출력 
   else puts(max_arr);//아닐경우 출력 

   for(int i=0;i<n;i++)free(y[i]);//메모리해제
   free(y);//메모리해제
}