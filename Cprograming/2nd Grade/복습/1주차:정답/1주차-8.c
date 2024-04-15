#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 정답 */
/*
N명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를 입력 받아, 
    각 학생 의 평균 성적과 GREAT 혹은 BAD을 출력하는 프로그램을 작성하시오.
◦ 평균은 소수 첫째 자리까지 출력
◦ GREAT 혹은 BAD는 다음 기준을 적용하여 출력:
- 국어, 영어, 수학 성적 중 어느 한 과목이라도 90 이상일 경우 GREAT 출력
- 국어, 영어, 수학 성적 중 어느 한 과목이라도 70 미만일 경우 BAD 출력
- GREAT 여부를 BAD 여부보다 먼저 출력하며, 
    GREAT과 BAD 모두 출력될 경우 공백으로 구분
*/

struct student{
    /* data */
    char name[10];
    int korean;
    int english;
    int math;
    float avg;
}info;

int main(){
    int N; scanf("%d",&N);
    float avg[3] = {};
    struct student* info = (struct student*)malloc(sizeof(struct student) *N);
    for(int i=0;i<N;i++){
        scanf("%s %d %d %d",info[i].name, &info[i].korean,&info[i].english,&info[i].math);
        avg[0] += info[i].korean;
        avg[1] +=  info[i].english;
        avg[2] += info[i].math;
        info[i].avg = (info[i].korean+info[i].english+info[i].math)/3;
    }
    for(int i=0;i<3;i++)avg[i] /= N;
    // for(int i=0;i<3;i++) printf("%f\n",avg[i]);
    /*
    ◦ GREAT 혹은 BAD는 다음 기준을 적용하여 출력:
- 국어, 영어, 수학 성적 중 어느 한 과목이라도 90 이상일 경우 GREAT 출력
- 국어, 영어, 수학 성적 중 어느 한 과목이라도 70 미만일 경우 BAD 출력
- GREAT 여부를 BAD 여부보다 먼저 출력하며, GREAT과 BAD 모두 출력될 경우 공백으로
구분
    */
   for(int i=0;i<N;i++){
    printf("%s %.1f",info[i].name,info[i].avg);
        if(info[i].korean >= 90 || info[i].english >= 90 || info[i].math>=90){
            printf(" GREAT");
            }
        if(info[i].korean < 70 || info[i].english < 70 || info[i].math < 70)
            printf(" BAD");
        printf("\n");
   }
} 
/*
2
Kim 100 82 34 
Young 90 100 99
*/