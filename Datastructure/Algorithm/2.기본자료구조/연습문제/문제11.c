#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
/*dayfyear 함수를 변수 i와 days를 사용하지 않고 구현하라.*/
int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},//평년
    {31,29,31,30,31,30,31,31,30,31,30,31}//윤년
};

//year년이 윤년인지 확인하는 함수
int isleap(int year){
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 ==0);
}

int dayfyear(int year, int mon, int day){
    int cnt = 1;
    while(mon > cnt){
        day += mdays[isleap(year)][cnt-1];
        cnt ++;
    }
    return day;
}

int main(){
    int year,mon,day,rty;
    do{
        printf("년: ");scanf("%d",&year);
        printf("월: ");scanf("%d",&mon);
        printf("일: ");scanf("%d",&day);
        printf("%d년의 %d일째입니다.\n",year,dayfyear(year,mon,day));

        printf("다시 할까요?(예: 1 / 아니오: 0): ");scanf("%d",&rty);
    }while(rty == 1);
   
    

}