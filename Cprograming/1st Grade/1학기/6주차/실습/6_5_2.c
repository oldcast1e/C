#include  <stdio.h>
int main() 
{
    int n,i,j;//3개의 정수형 변수 선언
    scanf("%d",&n);//정수 입력받음
    for(i=n;i>0;i--){//n부터 1까지
        for(j=i;j>0;j--){//행(갈수록 작아짐)
            printf("*");
        }
        printf("\n");//열마다 띄움
    }
    
}
