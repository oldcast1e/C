#include <stdio.h>
#include <string.h>

struct quiz {//구조체 정의
   char name[10];//이름 
   int s1;int s2;int s3;//성적
   float avg;//평균
}stu[10],*rst;//구조체 선언

void read_data(struct quiz *p) {//read_data함수 정의
   for (int i = 0; i < 10; i++) {//10번 반복
      scanf("%s %d %d %d", &(p + i)->name, &(p + i)->s1, &(p + i)->s2, &(p + i)->s3);
      //멤버 입력받음
   }
}

void cal_avg(struct quiz *p) {//cal_avg함수 정의
   p->avg =(p->s1 + p->s2 + p->s3)/3.00;//평균 구하기
   //rintf("%.2f", p->avg);
}

void sort(struct quiz sp[10]) {//sort함수 선언
   for (int i = 0; i < 10; i++) {//10번 반복
      for (int j = 0; j < 9; j++) {//9번 반복
         if (sp[j].avg < sp[j+1].avg) {//해당 평균이 비교하는 평균보다 작으면
            struct quiz tmp;//구조체 선언
            tmp = sp[j];//임의의 값에 저장
            sp[j] = sp[j + 1];
            sp[j + 1] = tmp;//값 체인지
         }
      }
   }
}

void print_score(struct quiz *score) {//print_score함수 선언
   printf("%s %.2f\n", score->name, score->avg);
   printf("%s %.2f\n", (score+9)->name, (score+9)->avg);
   
   printf("%s %.2f\n", (score+7)->name, (score+7)->avg);
   printf("%s %.2f\n", (score+8)->name, (score+8)->avg);
   printf("%s %.2f\n", (score+9)->name, (score+9)->avg);
   //최고평균점, 최저평균점, 하위 30%의 평균점을 받은 학생들의 이름과 평균 점수를 출력 합니다. 
   //평균은 소수점 이하 둘째자리까지 출력합니다.
   
}

int main() {//메인 ㅎ마수
   rst = &stu;//구조체 선언

   read_data(rst);//함수 실헹
   for (int i = 0; i < 10; i++) {
      cal_avg(rst+i);//함수 실행 = 입력받음
   }
   
   sort(stu);//힘스 실행
   print_score(rst);//출력 함수 실행

   return 0;
}


