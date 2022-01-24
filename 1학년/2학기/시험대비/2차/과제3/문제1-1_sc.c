#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct student{
    /* data */
    char name[10];
    char schoolnum[11];
    char score;
}st[5];


/*
◦ 이름 : 공백을 포함하지 않고 길이가 최대 9인 문자열 (널 문자까지 10 바이트만 선언하기) 
◦ 학번 : 공백을 포함하지 않고 길이가 10인 문자열이고, 첫 4자리는 입학년도를 의미
◦ 지난학기 평균학점 : A, B, F 중 한 개의 학점 (문자)
*/
int main(){

    char info[10];
    for(int i=0;i<5;i++)
        scanf("%s %s %c",st[i].name,st[i].schoolnum,&st[i].score);getchar();
    //그다음 찾고자 하는 학생의 이름을 입력하면, 이 학생의 학번과 지난학기 평균학점을 출력 하시오.
    scanf("%s",info);
    for(int i=0;i<5;i++){
        if(strcmp(info,st[i].name)==0){
            printf(" %s %c",st[i].schoolnum,st[i].score);
            break;
        }
    }

}
/**
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
 * 
 */