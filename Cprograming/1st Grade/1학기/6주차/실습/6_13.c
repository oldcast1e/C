#include<stdio.h>
int main(){
    
    int n,m,rst;//입력받을 값
    int num=1,cnt=0;
 
    scanf("%d",&n);//n의 값을 입력받음
    while(num<=n){

        if(num>10){//10의 자리 이상인 경우
            m = num;
            while(m>0){//n이 양수일때 반복
                rst = m%10;//n의 나머지 연산=3이있는지 확인
                if(rst==3)
                    cnt ++;//3인 경우 카운트를 1올림
                m /=10;//n의 자리수를 낮춤
             }
        }
        else{//1의 자리인경우
            if(num==3)//3인 경우
                cnt +=1;//카운트를 올림
        }
        num++;//반복 조건
    }
    printf("%d",cnt);//3이 나온 횟수 출력
}