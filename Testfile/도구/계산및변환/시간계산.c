#include<stdio.h>
int main(){

    int N;//임의 정수(초) 선언
    int h,m,s;//시간,분,초 서언
    scanf("%d",&N);// 입력받음
    h = N/3600;//시간 
    m = N/60%60;//분, 나머지 연산을 한 이유는 분은 60까지이므로
    s = N%60;//초
    printf("%d:%d:%d",h,m,s);


}    