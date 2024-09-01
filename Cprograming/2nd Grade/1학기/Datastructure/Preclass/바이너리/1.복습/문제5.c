#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 5 ] 사용자로부터 두 개의 시각을 입력 받아서 두 시각 사이의 차이를 계산하여 출력하는 프로그램을 작성하시오.
◦ 시각은 시, 분, 초로 구성되는 구조체로 정의하라.
◦ 두 번째 시각이 첫 번째 시각보다 항상 늦은 시각이라고 가정한다.
◦ 시간차가 없는 경우에 분과 초만 출력하는 것이 아니라 시 분 초, 0 10 20 으로 출력한다.
 */

struct time{
    /* data */
    int hour;
    int min;
    int sec;
}pre,now,rst;

int main(){
    int previous,nowtime,result;
    scanf("%d %d %d",&pre.hour,&pre.min,&pre.sec);
    scanf("%d %d %d",&now.hour,&now.min,&now.sec);
    previous = pre.hour*3600 + pre.min*60 + pre.sec;
    nowtime = now.hour*3600 + now.min*60 + now.sec;
    result = nowtime-previous;
    printf("%d %d %d",result/3600,result/60%60,result%60);

}