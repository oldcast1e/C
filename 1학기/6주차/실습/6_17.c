#include  <stdio.h>
int main() 
{
    int n,m=1,sum=0;//3개의 변수 선언
    scanf("%d",&n);//정수를 입력받음
    for( ; ; ){//for문의 무한 반복
        if(n>=m){//n이m보다 큰 경우
            sum += m;//m을 sum변수에 더함
        }
        if(n==m)//두 수가 같은 경우
            break;//반복문 종료
        m++;
        
    }
    printf("%d",sum);//합을 출력


}

