#include <stdio.h>
#include <string.h>

typedef struct student {//student 구조체 정의
   char subject[51];//학과
   char id[8];//학번
}student;//구조체 정의

void print_arr(int n, student st[]) {//print_arr 함수 정의
   for (int j = 0; j < n; j++) {//n번 반복
      printf("%s %s\n", st[j].subject, st[j].id);//출력
   }
}
void swap1(int n, student st[100]) {//swap1함수 정의
   for (int i = 0; i < n; i++) {//n번 반복
      for (int j = 0; j < n - 1; j++) {// n - 1반복
         if (atoi(st[j].id) > atoi(st[j + 1].id)) {//정수화한 값 비교
            student tmp;//임의 구조체 선언
            tmp = st[j];
            st[j] = st[j + 1];
            st[j + 1] = tmp;//스왑1
         }
      }
   }

}

void swap2(int n, student st[]) {//스왑2 함수 선언
   for (int i = 0; i < n; i++) {//n번 반복
      for (int j = 0; j < n - 1; j++) {  // n - 1번반복
         if (strcmp(st[j].subject, st[j + 1].subject) > 0) {//해당 조건 만족시
            student tmp;
            tmp = st[j];
            st[j] = st[j + 1];
            st[j + 1] = tmp;//스왑2
         }
      }
   }

}

int main()//메인 함수
{
   student st[100], *pst = st;//크기 100의 구조체 배열 서언
   int n;//입력받을 정수형 변수 n
   scanf("%d", &n);//입력받음
   getchar();//엔터값 날리기

   for (int i = 0; i < n; i++) {//n번 반복 정보 입력받기
      gets(st[i].subject);
      gets(st[i].id);
   }
   swap1(n, st);//스왑1
   swap2(n, pst);//스왑2

   print_arr(n, pst);//출력

}