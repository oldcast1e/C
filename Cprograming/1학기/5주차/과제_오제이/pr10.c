#include<stdio.h>
int main(){

    int l,e,m;//국어,영어,수학 점수 선언
    scanf("%d %d %d",&l,&e,&m);   //3개의 점수를 입력받음
    double avg = (l+m+e)/3;//평균 = 3개과목을 3으로 나눈 값

    if(avg>=91.5)//평균이 91.5보다 크거나 같은 경우
        printf("A");//A출력
    else if(avg>=85.5)//평균이 85.5보다 크거나 같은 경우
        printf("B");//B출력
    else if(avg>=80.5)//평균이 80.5보다 크거나 같은 경우
        printf("C");//C출력
    else//아무것도 조건을 만족시키지 못한 경우 
        printf("F");//F출력

    if(l==100 || e==100 || m==100)
        printf("Good");//3개중 하나라고 100점이 있는 경우 Good출력
    if(l<60 || e<60 || m<60)
        printf("Bad");//3개중 하나라고 60점 미만이 있는 경우 Bad출력

}