#include  <stdio.h>

int isLeapYear(int),getTotaloNumberOfLeapYear(int,int);

int main(){
    
    int startYear = 0,endYear = 0;
    scanf("%d%d",&startYear,&endYear);
    printf("%d",getTotaloNumberOfLeapYear(startYear,endYear));
}

int isLeapYear(int year){
    if(year%4==0 && year%100!=0 || year %400==0) return 1;
    return 0;
}

int getTotaloNumberOfLeapYear(int startYear,int endYear){
    
    int cnt = 0;
    int rst;
    for(int i=startYear;i<=endYear;i++){
        rst = isLeapYear(i);
        if(rst == 1) cnt++;
    }
    return cnt;
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가

