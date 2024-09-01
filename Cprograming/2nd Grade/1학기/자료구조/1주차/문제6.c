#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 6 ] 5명 학생의 이름과 기말고사 점수를 입력 받아, 
평균 이하의 점수를 받은 학생의 이름 을 출력하는 프로그램을 작성하시오.
◦ 학생의 이름은 공백 없이 최대 9개 영어 문자이다.
◦ 1명의 학생의 정보 (이름과 점수)를 저장하는 구조체를 정의하고, 5명의 학생의 정보는 구조
체 배열에 저장하시오.
 */

struct student{
    /* data */
    char name[10];
    double score;
};

int main(){
    double avg = 0;
    struct student system[5];
    for(int i=0;i<5;i++){scanf("%s %lf",system[i].name,&system[i].score); avg += system[i].score; }
    avg /= 5;
    for(int i=0;i<5;i++)if(avg >= system[i].score)puts(system[i].name);

}