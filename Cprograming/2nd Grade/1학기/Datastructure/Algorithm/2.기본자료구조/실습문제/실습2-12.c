#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*한 해의 지난 날 수를 계산하는 프로그램*/

//각 달의 날의 수
int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},//평년
    {31,29,31,30,31,30,31,31,30,31,30,31}//윤년
};

//year년이 윤년인지 확인하는 함수
int isleap(int year){
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 ==0);
}

int dayfyear(int year, int mon, int day){
    for(int i = 1; i< mon; i++) day += mdays[isleap(year)][i-1];
    /**
    인자로 받은 달의 이전 달 까지 일 수 를 증가한다.
    == 윤년과 윤년이 아닌 달의 1달 일 수가 다르므로 윤년을 파악한 후 인자로 받은 달 전까지 일 수를 더한다.

    이후 지난 날짜 (day)를 반환한다.
     */
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