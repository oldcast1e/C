#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 성공 */

/* 
[ 문제 6 ] 5명 학생의 이름과 기말고사 점수를 입력 받아, 평균 이하의 점수를 받은 학생의 이름 을 출력하는 프로그램을 작성하시오.
◦ 학생의 이름은 공백 없이 최대 9개 영어 문자이다.
◦ 1명의 학생의 정보 (이름과 점수)를 저장하는 구조체를 정의하고, 5명의 학생의 정보는 구조
체 배열에 저장하시오.
 */
struct student{
    /* data */
    char name[10];
    int score;
}info[5];

/*
akim 75 
bkim 85 
ckim 65 
dkim 95 
ekim 100

*/
int main(){
    int avg = 0;
    for(int i=0;i<5;i++){scanf("%s %d",info[i].name, &info[i].score);getchar();}
    for(int i=0;i<5;i++) {avg += info[i].score;}avg /= 5; //printf("avg = %d",avg);
    for(int i=0;i<5;i++){if(avg > info[i].score) printf("%s\n",info[i].name);}

} 
//abcde
/*
10 20 30
12 05 10

1 10 20
3 20 30
*/
