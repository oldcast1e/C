#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float fir,rst=0,out;
    
    scanf("%f",&fir);rst = fir;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        rst = rst + rst * (b*0.01);
        // printf(">> %.02f\n",rst);
    }printf("%.0f\n",rst - fir); out = rst - fir;
    if(out>0)printf("good");
    else if(out==0) printf("same");
    else printf("bad");
 
} 
/*
첫째줄에 투자한 액수 a가 입력됩니다. (100 <= a <= 10,000)
둘째 줄에 투자 일 수 b가 입력됩니다.(1 <= b <= 10)

그 다음줄에 일별 변동폭인 데이터가 날짜 갯수(b개)만큼 퍼센트 정수로 입력됩니다.
 (변동폭는 음수도 될 수 있습니다.) ( 범위 -100 ~ +100)

이 사람의 순수익(=총 수익(최종 값) - 총 비용(투자한 액수))을 
소수점 첫째 자리에서 반올림하여 첫째 줄에 출력한다.
*/