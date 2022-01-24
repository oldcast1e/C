#include<stdio.h>
int main(){

    int n;//정수형 변수 선언
    scanf("%d",&n);
    int a=1,b=n;//두개의 정수형 변수선언

    for(int i=1;i<=n;i++){//열

        for(int j=1;j<=n;j++){//행
            if(j==a || j ==b){//X가 출력되는 조건
                printf("X ");
            }
            else    //아닌 경우 O출력
                printf("O ");
            }
        a +=1;//X의 위치 변화
        b-=1;//X의 위치 변화
        printf("\n");//열마다 띄움
    }
}

