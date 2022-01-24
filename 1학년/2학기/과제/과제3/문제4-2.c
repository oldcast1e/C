#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct bike_info {//구조체 선언
   int num;
   int call;
   char type;
   char is_y;
   int s_days;
   int time;
   double money;
};

void input(struct bike_info *p, int N);//함수 원형 선언
void compute(struct bike_info *p, int N);//함수 원형 선언
void display(struct bike_info *p, int N);//함수 원형 선언
void bike_info_sort(struct bike_info *p, int N);//함수 원형 선언

int main()
{
   struct bike_info bike[100], *pb = bike;//구조체 선언
   int n;
   scanf("%d", &n);//입력받기/
   input(pb, n);//힘수 싫ㅇ
   compute(pb, n);//함수 실행
   bike_info_sort(pb, n);//함수 실행

   return 0;
}

void input(struct bike_info *p, int N) {//함수 정의
   for (int i = 0; i < N; i++) {
      scanf("%d %d %c", &(p + i)->num, &(p + i)->call, &(p + i)->type);
      //printf("%d %d %c", (p + i)->num, (p + i)->call, (p + i)->type);
      if ((p + i)->type == 'S') {//s이면
         int days;//
         char is;//매개변수 선언
         getchar();
         scanf("%c %d ", &(p + i)->is_y, &(p + i)->s_days);
         //printf(" %c %d ", (p + i)->is_y, (p + i)->s_days);
      }
      int t;
      scanf("%d",&t);//입력받기
      (p + i)->time = t;
      //printf("%d\n",(p + i)->time);
   }
}
void compute(struct bike_info *p,int N) {//
   struct bike_info *ori_p = p;
   for (p; p < ori_p + N; p++) {
      p->money = 0;
      int t = p->time - 60;
      int mul = (t / 5);//값 변화

      if ((p)->type == 'S') {//S이면
         if (p->is_y == 'N')  {//N이면
            if (p->s_days == 7) {
               p->money += 3000;

            }
            else if (p->s_days == 30) {
               p->money += 5000;
            }
            else if (p->s_days == 180) {
               p->money += 15000;
            }

         }
      }
      else {
         p->money += 1000;
      }

      if (mul > 0) {
         p->money += mul * 200;
      }

   }
}

void display(struct bike_info *p, int N) {
   struct bike_info *ori_p = p;
   for (p=0; p < ori_p + N; p++) {
      printf("%d %d %c %.0lf\n", p->num, p->call, p->type, p->money);
   }
}

void bike_info_sort(struct bike_info *p, int N) {
   int k = 0;
   int d_inx= 0;
   double d_total = 0;
   double s_total = 0;
   double total = 0;

   for (struct bike_info *j = p; j < p + N ; j++) {
      for (struct bike_info *i = p; i < p + N - 1; i++) {
         //printf("%d\n", (i + 1)->num);
         if ((i+1)->type == 'D') {
            struct bike_info tmp = *i;
            *i = *(i + 1);
            *(i + 1) = tmp;
         }
      }
   }

   for (struct bike_info *j = p; j < p + N; j++) {
      if ((j)->type == 'D') d_inx++;
   }
   //printf("sort1 d_inx=%d \n",d_inx);
   //display(p, N);

   for (struct bike_info *j = p; j < p + d_inx ; j++) {
      for (struct bike_info *i = p; i < p + d_inx - 1; i++) {
         //printf("i = %d i+1 = %d\n", i->num ,(i + 1)->num);
         if (i->num > (i+1)->num) {
            struct bike_info tmp = *i;
            *i = *(i+1);
            *(i + 1) = tmp;
         }
      }
   }
   //printf("sort2\n");
   //display(p, N);

   for (struct bike_info *j = p; j < p + d_inx; j++) {
      d_total += j->money;
   }
   for (struct bike_info *j = p + d_inx; j < p + N; j++) {
      s_total += j->money;
   }
   total = s_total + d_total;

   for (struct bike_info *j = p+d_inx; j < p + N ; j++) {
      for (struct bike_info *i = p+d_inx; i < p + N - 1; i++) {
         if (i->num > (i+1)->num) {
            struct bike_info tmp = *i;
            *i = *(i+1);
            *(i + 1) = tmp;
         }
      }
   }

   display(p, N);
   printf("%.0lf %.0lf %.0lf", d_total,s_total,total);
}