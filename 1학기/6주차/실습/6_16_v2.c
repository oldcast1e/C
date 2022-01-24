#include  <stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);//3~18사이의 정수 입력받음
    int a,b,c,cnt;//반복을 담당할 3개의 정수형 변수 선언
    for(a=1;a<=6;a++){//첫번째 주사위
        for(b=1;b<=6;b++){//두번째 주사위
            for(c=1;c<=6;c++){//3번째 주사위
                if(a+b+c==n){
                    if(cnt!=0)//cnt가 0이 아닌 경우=첫번째만 열을 띄우지 않는다
                        printf("\n");//열을 띄움
                    printf("%d %d %d",a,b,c);//3개의 주사위 값 출력
                    cnt ++;//cnt에 1을 더함
                }
                } 
                }
                
            }  

}

