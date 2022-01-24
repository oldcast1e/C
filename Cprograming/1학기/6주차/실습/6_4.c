#include<stdio.h>
int main(){

    int N,M,min,cnt;//N,M등의 변수 선언
    scanf("%d %d",&N,&M);//두 개의 정수 입력받음
    min = (N>M?M:N);//두정수중 최솟값 찾음
    cnt = min; //cnt에 대입
    while(min>0){//최솟값이 0보다 큰 경우 반복

        if(N%cnt==0 && M%cnt==0){//N,M의 최대공약수 찾음
            printf("%d",cnt);//찾으면 종료
            break;
        }
        cnt-=1;//
        min -=1;//두변수의 값을 동일하게 -1함
    }
    
}