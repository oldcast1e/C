#include  <stdio.h>
int main() 
{
    int N,U,cnt=0;//정수와 입력받을 변수,카운트 값 선언
    scanf("%d",&N);//정수를 입력받음

    while(N!=U){//정수가 입력받은 값과 다른 경우
        scanf("%d",&U);//입력값을 받음
        if(N>U){//정수보다 입력값이 작은 경우
            printf("%d<?\n",U);//힌트 출력
            cnt +=1;//카운트 +1
        }
        else if(N<U){//정수보다 입력값이 큰 경우
            printf("%d>?\n",U);//힌트 출력
            cnt +=1;//카운트 +1
        }
        else if(N==U){//정수와 입력값이 같은 경우
            printf("%d==?\n",U);//힌트 출력
            cnt +=1;//카운트 +1
            break;//종료
        
        }
    }
    printf("%d",cnt);//시도횟수(카운트)출력
}
