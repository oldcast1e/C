#include<stdio.h>
int main(){

    int N,i=1;
    int j = 1;//정수형 변수 3개 선언

    int a=1,b=1;//정수형 변수 2개 선언
    scanf("%d",&N);//N의 값을 입력받음

    while(i<=N){//반복
        
        for(j=a;j<=b;j++){
            printf(" %d",j%10);
        }//삼각형으로 숫자 출력
        printf("\n");//출력후 줄 띄우기
        a += i;
        b +=i+1;// a,b는 시작 및 마지막 숫자 설정
        i +=1;//반복 조건
        
    }
    
}
