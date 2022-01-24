#include  <stdio.h>
int main(){
    
    int x[10];//10개의 요소 배열 선언
    int sum1=0,sum2=0,sum3=0;//1,2,3의 횟수 저장 변수 선언
    for(int i=0;i<10;i++){
        scanf("%d",&x[i]);//10번 반복하여 배열값 입력 받음
    }
    for(int i=0;i<10;i++){//10번 반복하여
        if(x[i]==1)//해당 번호의 요소가 1인 경우
            sum1 ++;//해당 합 변수에 더함
        else if(x[i]==2)//해당 번호의 요소가 2인 경우
            sum2 ++;//해당 합 변수에 더함
        else if(x[i]==3)//해당 번호의 요소가 3인 경우
            sum3 ++;//해당 합 변수에 더함
    }

    printf("1:");
    for(int j=0;j<sum1;j++){//1:을 출력하고 해당 합 변수 만큼 반복하여
        printf("*");//별 출력
    }
    printf("\n");
    printf("2:");
    for(int j=0;j<sum2;j++){//2:을 출력하고 해당 합 변수 만큼 반복하여
        printf("*");//별 출력
    }
    printf("\n");
    printf("3:");
    for(int j=0;j<sum3;j++){//3:을 출력하고 해당 합 변수 만큼 반복하여
        printf("*");//별 출력
    }



}
