#include  <stdio.h>

int main(){
    
    int X[10],max;

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&X[i]);//x의 요소를 입력받음 
    }
    max = X[0];//max를 X배열의 첫번째 요소로 정의(비교하기 쉽게 초기화)
    for(int i=0;i<10;i++){//10번 반복하여
        if(X[i]>=max)//X의 요소값이 max보다 큰 경우
            max = X[i];//max값에 저장
    }
    printf("%d",max);//최댓값 출력
   

    return 0;
}
