#include<stdio.h>
int main(){

    int n,m,rst;//정수 3개와 펙토리얼 값을 저장할 벼눗 선언
    scanf("%d %d",&n,&m);//정수 입력받음

    for(int i=n;i<=m;i++){//열
        rst =1;//펙토리얼 값 초기화
        printf("%d!=1",i);//1열로 문장을 출력하기 위해 반복할 문장과 띄움
        for(int j=1+1;j<=i;j++){//행

            printf("*%d",j);//곱하기 코드를 값을 올려반복해서 출력
        }
        for(int k=1;k<=i;k++){//펙토리얼 값
            rst = rst*k;//펙토리얼 계산
        }
        printf("=%d",rst);//펙토리얼 값 출력
        printf("\n");//열을 띄움
    }   
}