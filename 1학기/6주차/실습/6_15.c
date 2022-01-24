#include<stdio.h>
int main(){

    int n,bef,sum,cnt=0;//정수형 변수 4개 선언
    scanf("%d",&n);//10이상의 정수입력받음
    int rst;//결과값 저장할 변수 선언
    while(cnt==0){//1차 반복
        sum =0;//정수의 각자리 합 변수를 0으로 초기화
        while(n>0){//n이 0보다 클때
            sum += n%10;//나머지 연산을 통해 각자리를 sum변수에 저장
            n /=10;//한자리수 씩 줄임
        }
        if(sum>=10){//sum이 두자리인경우
            n=sum;//sum을n으로 바꿔 재반복
        }
        else{//아닌 경우 cnt를 1로 바꿔 반복을 없애고 break
            cnt =1;
            break;
        }
    }
    printf("%d",sum);//디지털 근 출력

}