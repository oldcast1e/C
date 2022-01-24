#include<stdio.h>
int main(){
    int a,b,c;//3개의 변수 선언
    int max,min;//최소,최댓값 선언
    scanf("%d %d %d",&a,&b,&c);//3개 입력받음
    if(a<b && a<c)//a가 가장 적은 경우
        min = a;//최솟값을 a로
    else if(b<a && b<c)//b가 가장 적은 경우
        min = b;//최솟값을 b로
    else if(c<a && c<b)//c가 가장 적은 경우
        min = c;//최솟값을 c로
    
    if(a>b && a>c)//a가 가장 큰 경우
        max = a;//최솟값을 a로
    else if(b>a && b>c)//b가 가장 큰 경우
        max = b;//최솟값을 b로
    else if(c>a && c>b)//c가 가장 큰 경우
        max = c;//최솟값을 c로
    
    printf("%d %d",max,min);//최대 최소 출력
}