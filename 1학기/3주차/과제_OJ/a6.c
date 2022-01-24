#include<stdio.h>
int main(){

    int a,b,c,rst=-1;//3자리 정수 N, 각 자리를 저장한 변수 a,b,c 결과값의 초기값을 -1로 선언
    //-1로 선언한 이유는 결과값이 -1이 나올수 없기 때문 
    scanf("%d %d %d",&a,&b,&c);//숫자 3개 선언
    
    rst = (a<b && b<c || c<b && b<a?b:rst);//b가 중앙값인 경우. 즉 a와c 사이거나 c와a사이
    rst = (a<c && c<b || b<c && c<a?c:rst);//c가 중앙값인 경우. 즉 a와b 사이거나 b와a사이
    rst = (b<a && a<c || c<a && a<b?a:rst);//a가 중앙값인 경우. 즉 c와b 사이거나 c와b사이
    printf("%d",rst);//결과값 출력


    



}