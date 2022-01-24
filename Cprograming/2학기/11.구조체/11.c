#include <stdio.h>
#include <string.h>
struct student {//구조체 정의
   char name[10];//멤버 선언
   int score;
}stu[5],*sp;//구조체 선언

struct student * select_min(struct student * person) {//함수 정의
   int min = person->score;//최소값 초기화
   struct student * rst;//구조체 포인터 정의
   rst = person;//

   for (int i = 0; i < 5; i++) {//5번 반복
      if (min > (person + i)->score) {//최소값보다 작으면
         rst = person + i;//결과 초기화
         min = (person + i)->score;//최솟값 초기화
      }
   }

   return rst;//결과 출력
}

int main() {//메인 함수
   sp = &stu;//
   struct student * result;//구조체 선언
   for (int i = 0; i < 5; i++) {//5번 반복
      scanf("%s %d", &(sp+i)->name, &(sp+i)->score);//멤버 입력
   }
   sp = &stu;//저장
   result = select_min(sp);//함수 실행

   printf("%s %d", result->name, result->score);//결과출력

}
