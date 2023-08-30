#include<stdio.h>
int main(){

    int n;//정수형식 n 선언
    char score;//char 형식 변수 선언
    scanf("%d",&n);
    if(n%2==0){//2로 나눠떨어지는 경우
        if(n%3==0)//3으로 나눠떨어지는 경우
            if(n%5==0)//5로 나눠떨어지는 경우
                score = 'A';//A
            else
                score = 'B'; //아닌경우 B
        else
            if(n%5==0)//3으로 나눠떨어지지얺고 5로 나눠떨어지는 경우
                score = 'C';//C
            else
                score = 'E';//아닌경워 E
    }
    else   
        if(n%3==0)//2로나눠떨어지지않고 3으로 나눠떨어지는 경우

            if(n%5==0)//위 조건 충족, 5로 나눠떨어지는 경우
                score = 'D';//D
            else
                score = 'E';//아닌경우 E
        else

            if(n%5==0)//2로 나눠떨어지지않고 3으로 나눠떨어지지 않는 경우
                score = 'E';//E
            else
                score = 'N';//모든 조건 미 충족시 N
    printf("%c",score);//스코어 출력

}