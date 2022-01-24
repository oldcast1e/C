#include  <stdio.h>
int main() 
{
    int n,i,j;//3개 정수형 변수 선언
    scanf("%d",&n);//정수 입력받음
    for(i=n;i>0;i--){//전 문제와는 반대로
        for(j=2*i-1;j>0;j--){//별을 아래로 갈 수록 적게 출력
            printf("*");
        }
        printf("\n");//열마다 띄움
    }
    
}
