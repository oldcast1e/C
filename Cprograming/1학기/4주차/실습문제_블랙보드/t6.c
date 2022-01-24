//5-3
#include<stdio.h>
int main(){

    int a,b,c,d,e,sum;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);//숫자5개와 합 변수 선언하고 숫자를 입력받음
    if (a>0)
        sum += a;
    if (b>0)
        sum += b;
        //각각의 숫자가 양수인지 비교하고 양수이면 sum변수에 더함
    if (c>0)
        sum += c;
    if (d>0)
        sum += d;
        //각각의 숫자가 양수인지 비교하고 양수이면 sum변수에 더함
    if (e>0)
        sum += e;
    
    printf("%d",sum);//더한 값 출력
}