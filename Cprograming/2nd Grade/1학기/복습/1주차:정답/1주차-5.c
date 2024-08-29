#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 성공 */

/*
사용자로부터 두 개의 시각을 입력 받아서 
두 시각 사이의 차이를 계산하여 출력하는 프로그램을 작성하시오.

10 20 30 ↦ 10시 20분 30초 
12 05 10 ↦ 12시 05분 10초

*/
int main(){
    
    int h1,m1,s1,h2,m2,s2, time1, time2;
    int hour,min,sec;
    scanf("%d %d %d",&h1,&m1,&s1);
    scanf("%d %d %d",&h2,&m2,&s2);
    time1 = h1*3600 + m1*60 +s1;
    time2 = h2*3600 + m2*60 +s2;

    int time = time2 -  time1;
    hour = (time/3600)%24;
    min = time/60%60;
    sec = time%60;
    printf("%d %d %d",hour,min,sec);
} 
//abcde
/*
10 20 30
12 05 10

1 10 20
3 20 30
*/
