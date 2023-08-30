#include  <stdio.h>

int main(){
    
    int X[10],key;//크기가 10인 배열과 출력조건key변수 선언

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&X[i]);//x의 요소를 입력받음 
    }

    for(int i=0;i<10;i++){//10번 반복하여
        key = 1;//key의 값을 1로 초기화(1이면 출력을 수행함)
        if(i>0){
            for(int j=0;j<i;j++){//i번 반복하여
                if(X[i]==X[j])//입력받은 숫자와 그 숫자의 위치 전까지의 숫자를 비교하여 
                    key = 0;//동일한게 있으면 출력조건을 0으로
            }
            if(key==1)//출력조건이 1인 경우(참인경우)
                printf("%d",X[i]);//숫자를 출력하고
        }
        else//i=0d인 경우는 무조건 중복 없음
            printf("%d",X[0]);//0번째 출력
        
    }
    

    return 0;
}
