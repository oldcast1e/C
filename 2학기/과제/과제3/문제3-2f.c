#include <stdio.h>
#include <string.h>


struct hotel_info {
   char name[31];//이름
   int rank;//등급
   double reputaion;
   double distance;//거리와 평판
   char meal;//제공여부
};

int in_hotel_info(struct hotel_info *p);
void out_hotel_info(struct hotel_info *p, int N, int G, double D);

int main()
{
   struct hotel_info h[100], *p;//구조체 선언
   p = h;//포인터 연결
   int n = in_hotel_info(p);//저장

   int wantedrank;//
   double  wanteddis;//원하는 등급과 거리 선언


   scanf("%d %lf", &wantedrank, &wanteddis);//입력받음
   out_hotel_info(p, n, wantedrank, wanteddis);//함수 실행

   return 0;
}

int in_hotel_info(struct hotel_info *p) {//함수 정의
   for (int i = 0;; i++) {//무한 반복
      scanf("%s", (p + i)->name);//입력받고
      if (strcmp((p + i)->name, "0") == 0) {//0이면 종료
         //printf("1");
         return i;
         break;
      }
      scanf("%d %lf %lf %c", &(p + i)->rank, &(p + i)->reputaion, &(p + i)->distance, &(p + i)->meal);
      //아니면 계속 입력받음
      //printf("%s %d %lf %lf %c", (p + i)->name, (p + i)->rank, (p + i)->reputaion, (p + i)->distance, (p + i)->meal);
   }
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D) {
    //함수 선언
   struct hotel_info hotnfo;
   struct hotel_info * pr = &hotnfo;
   struct hotel_info h_name[100],*ph=h_name;
   //구조체 선언 및 포인터 연걸
   
   int k = 0;
   int cnt = 0;

   //두개의 정수형 변수 선언
   for (struct hotel_info * i = p; i < p + N; i++) {
       //조건에 부합ㅎ면
      if (((i)->rank >= G) && (i->distance <= D)) {
         *(h_name+k) = *i;
         k++;
         cnt = k;//매개변수 업데이트
      }
   }

   for (struct hotel_info * i = ph; i < ph + cnt; i++) {
      for (struct hotel_info * j = ph; j < ph + cnt-1; j++) {
         if (j->reputaion < (j + 1)->reputaion) {
            struct hotel_info p_tmp;
            p_tmp = *j;
            *j = *(j + 1);
            *(j + 1) = p_tmp;//조건에 부합하면 포인터에 저장
         }
         else if (j->reputaion == (j + 1)->reputaion) {
             //아니면
            if (strcmp(j->name, (j + 1)->name) > 0) {
               struct hotel_info p_tmp;//임의 구조체 선언
               p_tmp = *j;
               *j = *(j + 1);
               *(j + 1) = p_tmp;//스왑
            }
         }
      }
   }
   for (struct hotel_info * i = ph; i < ph + cnt; i++) {//결과값 출력
      printf("%s %d %.1lf %.1lf %c\n", (i)->name, (i)->rank, i->reputaion, i->distance, i->meal);
   }
}