#include  <stdio.h>
int main(){

    int T,n;//찾기 원하는 정수 T와 입력받을 정수 선언
    int apnum=0,smnum=0,lanum=0;//찾기원하는 정수의 등장 횟수와 작은 값/큰 값 등장횟수 0 초기화
    scanf("%d",&T);//찾기 원하는 숫자 입력받음
    while(1){//무한 반복
        scanf("%d",&n);//n입력받음
        if(n==0)//n이 0이면 종료
            break;

        if(n==T)//찾기 원하는 숫자와 일치
            apnum +=1;////찾기 원하는 숫자 등장횟수
        else if(n>T)//찾기 원하는 숫자보다 큼
            lanum +=1;//찾기 원하는 숫자보다 큰 숫자 등장횟수
        else if(n<T)//찾기 원하는 숫자보다 작음
            smnum +=1;//찾기 원하는 숫자보다 작은 값 등장횟수
        
    }
    printf("%d %d %d",apnum,smnum,lanum);
}