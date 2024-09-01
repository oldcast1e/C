#include  <stdio.h>
struct time//구조체 정의
{
    /* data */
    int hour,min,sec;//시간,분,초 선언
};

int main(){
    struct time t1,t2;//구조체 변수 선언
    int timesum1,timesum2,rst;//시간합 1,2 정의, 결과값 선언

    int rsthour,rstmin,rstsec;//출력할 값 선언
    scanf("%d %d %d",&t1.hour,&t1.min,&t1.sec);//첫번째 시간 입력
    scanf("%d %d %d",&t2.hour,&t2.min,&t2.sec);//두번째 시간 입력
    timesum2 = t2.hour*60*60 + t2.min*60 +t2.sec;//시간합 계산
    timesum1 = t1.hour*60*60 + t1.min*60 +t1.sec;
    rst = timesum2-timesum1;//시간차이

    // printf("%d\n",rst);
    rsthour = rst/3600%24;//시간
    rstmin = rst%3600/60;//분
    rstsec = rst%60;//초
    printf("%d %d %d",rsthour,rstmin,rstsec);//출력

}
/*
10 20 30
12 05 10
*/