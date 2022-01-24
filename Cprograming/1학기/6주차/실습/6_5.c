#include  <stdio.h>
int main() 
{
    int n,i,j;//3개의 변수 선언
    scanf("%d",&n);//정수값 입력받음
    for(i=0;i<n;i++){//열
        for(j=0;j<=i;j++){//행
            printf("*");//별 출력
        }
        printf("\n");//열 마다 띄움
    }
    
}
