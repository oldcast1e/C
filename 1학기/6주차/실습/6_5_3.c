#include  <stdio.h>
int main() 
{
    int n,i,j;//3개 정수형 변수 선언
    scanf("%d",&n);//정수 입력받음
    for(i=1;i<=n;i++){//열
        for(j=1;j<=2*i-1;j++){//행(별을 다르게 전 문제와 출력)
            printf("*");//2n-1개을 출력
        }
        printf("\n");//열마다 띄움
    }
    
}
