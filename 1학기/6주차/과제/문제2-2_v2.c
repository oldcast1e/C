#include  <stdio.h>
int main(){

    int N,M,K;//3개의 변수를 선언(N,M은 입력받을 정수,K는 N을 대신할 변수)
    scanf("%d %d",&N,&M);//두개의정수를 입력받음
    int maxnum=-1,maxcnt=0,maxsum=-1;
    //maxnum:약수의 개수가 가장 큰 수
    //maxcnt: 약수의 개수 <ok>
    //sum: 소인수 지수의 합_rst와 연관 <ok>
    int a,b;//두개의 정수를 선언(a는 약수찾을때,b는반복조건)
    int cnt,rst,sum,num;//약수의 개수를 찾는 과정에서 증가 및 감소될 변수

    while(N<=M){//N과 M의 범위내 반복
        cnt = 0;//cnt는 a가 일정할때 약수의 개수
        rst = 1;//rst는 약수의 개수를 만들기위한 곱 초기값
        sum = 0;//약수의 개수 합
        
        a = 2;//a는 2부터 시작(소인수분해이므로)
        K = N;//K에 N을 대입총 약수의 개수가 클 때 저장값
  
        b = N;//B에 N을 대입(N을 변화시킬수 없으므로)
        while(b>0){//b(N)가 0이상인 경우

            if(b%a==0){//a로 나누어 떨어지면
                b /= a;//b를 a로 나누고
                cnt +=1;//약수의 개수를 올림
            }
            else{//a로 나눠덜어지지 않으면
                a+=1;//a를 증가하고
                sum += cnt;//sum에 cnt를 저정후
                rst *= (cnt+1);//rst에 cnt+1을 곱함(소인수 지수를 이용해 약수의 개수를 구하므로)
                cnt =0;//cnt를 0으로 초기화(반복해서 재사용)
                if(b<=1){//b<=이면 더 이상 소인수 분해가 안되므로
                    break;//반복문 종료
                }
            
            }
        }
        
        if(rst>maxcnt){//약수의 개수가 가장 큰 수를 찾는 코드
            maxcnt = rst;//약수의 개수를에 rst대입
            maxnum = K;//약수의 개수가 가장 큰 수 K
            maxsum = sum;//소인수 지수의 합
        }
        N+=1;
    }
    printf("%d %d %d",maxnum,maxcnt,maxsum);//결과값 출력
    
    

    
}