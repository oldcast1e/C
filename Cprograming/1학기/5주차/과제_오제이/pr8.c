#include<stdio.h>
int main(){
    
    int N;//정수N선언
    scanf("%d",&N);//입력을 받는다
    if(N%4==0){//4로 나눠떨어지는경우
        if(N%100==0){//100으로 나눠떵어지는 경우
            if(N%400==0)//400으로 나눠떨어지는 경우
                printf("leap year");//leap year출력
            else
                printf("common year");//아닌경우 common year출력
        }
        else
            printf("leap year");//100으로 나눠떨어지지않는 경우 leap year출력
    }
    else   
        printf("common year");//4로 나눠떨어지지않는 경우 common year출력
}