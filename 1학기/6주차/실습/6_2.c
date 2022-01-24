#include  <stdio.h>
int main() 
{
    int n,sum=0;//정수와 합 변수 정의
    scanf("%d",&n);//정수 입력받음
    
    while(n!=0){//n이 0이 아닌경우 반복
        sum +=n;//합 변수에 n더함
        scanf("%d",&n);//n입력받음
        if(n==0)//n이 0일때 반복문 종료
            break;
    }
    printf("%d",sum);//합 출력
    


}
