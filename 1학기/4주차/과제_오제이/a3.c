#include  <stdio.h>
int main() 
{
    int a,b,c;//abc 숫자 3개 선언
    int k=0;//사칙 연산 횟수 초기화 = 0
    scanf("%d %d %d",&a,&b,&c);//입력받음
    if(a+b==c){//+사칙연산
        k +=1;//사칙 연산 횟수 +1
        printf("+\n");
        
    }
    if(a-b==c){//+사칙연산
        k +=1;//사칙 연산 횟수 +1
        printf("-\n");
        
    }
    if(a*b==c){//+사칙연산
        k +=1;//사칙 연산 횟수 +1
        printf("*\n");
        
    }
    if(a/b==c){//+사칙연산
        k +=1;//사칙 연산 횟수 +1
        printf("/");
        
    }
    if(k==0)//횟수가 0인경우=사칙연산이 한번도 없는 경우
        printf("Incorrect");//incorrect출력

}
